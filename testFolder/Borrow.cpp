#include "Borrow.h"

Borrow::Borrow(){}

Borrow::~Borrow(){}

bool Borrow::processBorrow(MediaCollection &movies, CustomerCollection &customers){ // UNTESTED
    
    Customer *customerInfo = nullptr;
    Media* mediaInfo = nullptr;

    // Customer not in CustomerCollection
    if (!customers.retrieve(this->getCustomerID(), customerInfo)) {

        // Error Condition
        cerr << "Borrow::processBorrow() | Customer " << this->getCustomerID() << " Does Not Exist" << endl;
        return false;
    }

    // Movies not in MediaCollection
    if (this->movie == nullptr || movies.retrieve(this->movie, mediaInfo)) {

        // Error Condition
        cerr << "Borrow::processBorrow() | Current Transaction Does Not Have an Associated Media" << endl;
        return false;
    }

    // Unable to remove Movie form stock
    if (!mediaInfo->decrementStock()) {

        // Error Condition
        cerr << "Borrow::processBorrow() | Media is Out of Stock (" << mediaInfo << ")" << endl;

    } else { // Happy Path

        customerInfo->borrowMedia(this->movie);
        customerInfo->addHistory(""); // (this)

        this->movie = nullptr;

        return true;
    }

    return false;
}
