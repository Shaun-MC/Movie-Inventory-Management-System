#include "Return.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Return::Return() {};

Return::~Return() {};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Return::ProcessReturn(MediaCollection &movies, CustomerCollection &customers){ // UNTESTED
    
    Customer* customerInfo = nullptr;
    Media* mediaInfo = nullptr;

    if (!customers.Retrieve(this->getCustomerID(), customerInfo)) {

        // Run Time Error Condition
        cerr << "Return::processReturn() | Customer " << this->getCustomerID() << " Does Not Exist" << endl;  
        return false;
    }

    if (this->movie == nullptr || !movies.Retrieve(this->movie, mediaInfo)) {
        
        // Run Time Error Condition
        cerr << "Return::processReturn() | Current Transaction Does Not Have an Associated Media" << endl;
        return false;
    }

    if (customerInfo->ReturnMedia(this->movie)) {

        // Run Time Error Condition
        cerr << "Return::processReturn() | Customer " << this->getCustomerID() << " Never Checked Out " << 
             dynamic_cast<Movie*>(this->movie)->getTitle() << endl;
    } else {

        delete this->movie;
        this->movie = nullptr;

        mediaInfo->IncrementStock();
        customerInfo->AddHistory(this->transactionLog);

        return true;
    }

    return false;
}
