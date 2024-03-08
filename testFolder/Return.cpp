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

    if (!customerInfo->ReturnMedia(mediaInfo)) {

        // Run Time Error Condition
        cerr << "Return::processReturn() | Customer " << this->getCustomerID() << " Never Checked Out " 
             << static_cast<Movie*>(mediaInfo)->getTitle() << endl;
            
        return false;

    } else { // Basic Course

        if (this->movie_type == MovieType::classic) {

            Classic* temp = static_cast<Classic*>(mediaInfo);

            this->transactionLog += ' ' + temp->getTitle() + " by " + temp->getDirector();

            temp->IncrementStock(static_cast<Classic*>(this->movie)->getMajorActor());
           
        } else {

            Movie* temp = static_cast<Movie*>(mediaInfo);

            this->transactionLog += " by " + temp->getDirector();

            mediaInfo->IncrementStock();
        } 
    }
    
    customerInfo->ReturnMedia(this->movie);
    customerInfo->AddHistory(this->transactionLog);

    delete this->movie;
    this->movie = nullptr;

    return true;
}
