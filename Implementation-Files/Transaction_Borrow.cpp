#include "Transaction_Borrow.h"

// Default constructor
Borrow::Borrow(){}

// Destructor
Borrow::~Borrow(){}

// Process a borrow transaction
bool Borrow::ProcessBorrow(MediaCollection &movies, CustomerCollection &customers){ 
    Customer *customerInfo = nullptr;
    Media* mediaInfo = nullptr;
 
    if (!customers.Retrieve(this->getCustomerID(), customerInfo)) {
        cerr << "ERROR: Borrow Transaction Failed -- Customer " << this->getCustomerID() << " does not exist" << endl;
        return false;
    }

    if (this->movie == nullptr) {
        cerr << "ERROR: Borrow::processBorrow() | Current Transaction Does Not Have an Associated Media" << endl;
        return false;

    } else if (!movies.Retrieve(this->movie, mediaInfo)) { 
        cerr << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory" << endl;

    } else { 
        bool flag = false;
        if (this->movie_type == MovieType::classic) {

            Classic* temp = dynamic_cast<Classic*>(mediaInfo); 
 
            this->transactionLog += ' ' + temp->getTitle() + " by " + temp->getDirector();
            
            if (!temp->DecrementStock(temp->getMajorActor())) {
                
                flag = true;
            }
        } else {

            Movie* temp = dynamic_cast<Movie*>(mediaInfo);
            this->transactionLog += " by " + temp->getDirector();
            
            if (!mediaInfo->DecrementStock()) {
               
                flag = true;
            }
        }

        if (flag == true) {
            cerr << "ERROR: Borrow Transaction Failed -- Not enough in the Stock" << endl;

        } else {
            customerInfo->BorrowMedia(mediaInfo);
            customerInfo->AddHistory(this->transactionLog);

            delete this->movie;
            this->movie = nullptr;

            return true;
        }
    }

    return false;
}
