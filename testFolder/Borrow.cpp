#include "Borrow.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Borrow::Borrow(){}

Borrow::~Borrow(){}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Borrow::ProcessBorrow(MediaCollection &movies, CustomerCollection &customers){ // UNTESTED
    
    Customer *customerInfo = nullptr;
    Media* mediaInfo = nullptr;

    // Customer not in CustomerCollection
    if (!customers.Retrieve(this->getCustomerID(), customerInfo)) {

        // Error Condition
        cerr << "Borrow::processBorrow() | Customer " << this->getCustomerID() << " Does Not Exist" << endl;
        return false;
    }

    // Movies not in MediaCollection
    if (this->movie == nullptr || movies.Retrieve(this->movie, mediaInfo)) {

        // Error Condition
        cerr << "Borrow::processBorrow() | Current Transaction Does Not Have an Associated Media" << endl;
        return false;
    }

    // Unable to remove Movie form stock
    if (!mediaInfo->DecrementStock()) {

        // Error Condition
        cerr << "Borrow::processBorrow() | Media is Out of Stock (" << mediaInfo << ")" << endl;

    } else { // Basic Course

        customerInfo->BorrowMedia(this->movie);
        customerInfo->AddHistory(this->entireTransaction);

        this->movie = nullptr;

        return true;
    }

    return false;
}
