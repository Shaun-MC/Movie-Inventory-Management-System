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
        cerr << "ERROR: Borrow Transaction Failed -- Customer " << this->getCustomerID() << " does not exist" << endl;
        //cerr << "Borrow::processBorrow() | Customer " <<  << " Does Not Exist" << endl;
        return false;
    }

    // Movies not in MediaCollection
    if (this->movie == nullptr) {

        // Error Condition
        cerr << "ERROR: Borrow::processBorrow() | Current Transaction Does Not Have an Associated Media" << endl;
        return false;
    } else if (!movies.Retrieve(this->movie, mediaInfo)) { // 

        cerr << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory" << endl;

        // cerr << "Borrow::processBorrow() | Could Not Retrieve " << dynamic_cast<Movie*>(this->movie)->getTitle()
        //      << " From the Collection" << endl;
    } else { // NOT GOOD DESIGN / STRUCTURE

        bool flag = false;

        if (this->movie_type == MovieType::classic) {

            Classic* temp = static_cast<Classic*>(mediaInfo);
 
            this->transactionLog += ' ' + temp->getTitle() + " by " + temp->getDirector();
            
            if (!temp->DecrementStock(temp->getMajorActor())) {
                
                flag = true;
            }
        } else {

            Movie* temp = static_cast<Movie*>(mediaInfo);
            this->transactionLog += " by " + temp->getDirector();
            
            // Unable to remove Movie form stock
            if (!mediaInfo->DecrementStock()) {
               
                flag = true;
            }
        }

        if (flag == true) {

            // Error Condition
            cerr << "ERROR: Borrow Transaction Failed -- Not enough in the Stock" << endl;

        } else {
            
            // Basic Course
            customerInfo->BorrowMedia(this->movie);
            
            customerInfo->AddHistory(this->transactionLog);

            this->movie = nullptr;

            return true;
        }
    }

    return false;
}
