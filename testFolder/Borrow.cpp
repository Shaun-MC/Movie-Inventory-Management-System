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
    if (this->movie == nullptr) {

        // Error Condition
        cerr << "Borrow::processBorrow() | Current Transaction Does Not Have an Associated Media" << endl;
        return false;
    } else if (!movies.Retrieve(this->movie, mediaInfo)) { // 

        cerr << "Borrow::processBorrow() | Could Not Retrieve " << dynamic_cast<Movie*>(this->movie)->getTitle()
             << " From the Collection" << endl;
    } else {

        // Unable to remove Movie form stock
        if (!mediaInfo->DecrementStock()) {

        // Error Condition
        cerr << "Borrow::processBorrow() | Media is Out of Stock (" << dynamic_cast<Movie*>(mediaInfo)->getTitle() << ")" << endl;

        } else { // Basic Course

            customerInfo->BorrowMedia(this->movie);
            customerInfo->AddHistory(this->transactionLog);

            this->movie = nullptr;

            return true;
        }
    }

    return false;
}
