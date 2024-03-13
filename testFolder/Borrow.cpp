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
        return false;
    }

    // Movies not in MediaCollection
    if (this->movie == nullptr) {

        // Error Condition
        cerr << "ERROR: Borrow::processBorrow() | Current Transaction Does Not Have an Associated Media" << endl;
        return false;
    } else if (!movies.Retrieve(this->movie, mediaInfo)) { // 

        cerr << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory" << endl;

    } else { // Condtionals are not well structure but work for the moment

        bool flag = false;

        // Logic specific for the Classic Movie Type
        if (this->movie_type == MovieType::classic) {

            Classic* temp = dynamic_cast<Classic*>(mediaInfo); // Needs to be a Classic* to have access to parameterized DecrementStock()
 
            this->transactionLog += ' ' + temp->getTitle() + " by " + temp->getDirector();
            
            if (!temp->DecrementStock(temp->getMajorActor())) {
                
                flag = true;
            }
        } else {

            Movie* temp = dynamic_cast<Movie*>(mediaInfo);
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
            customerInfo->BorrowMedia(mediaInfo);
            
            customerInfo->AddHistory(this->transactionLog);

            delete this->movie;
            this->movie = nullptr;

            return true;
        }
    }

    return false;
}
