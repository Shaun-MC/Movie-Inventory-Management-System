#include "Return.h"

// Constructor
Return::Return() {};

// Destructor
Return::~Return() {};

// Processes a return transaction
bool Return::ProcessReturn(MediaCollection &movies, CustomerCollection &customers){ 
    Customer* customerInfo = nullptr;
    Media* mediaInfo = nullptr;

    if (!customers.Retrieve(this->getCustomerID(), customerInfo)) {
        cerr << "Return::processReturn() | Customer " << this->getCustomerID() << " Does Not Exist" << endl;  
        return false;
    }

    if (this->movie == nullptr || !movies.Retrieve(this->movie, mediaInfo)) {
        cerr << "Return::processReturn() | Current Transaction Does Not Have an Associated Media" << endl;
        return false;
    }

    if (!customerInfo->ReturnMedia(mediaInfo)) {
        cerr << "Return::processReturn() | Customer " << this->getCustomerID() << " Never Checked Out " 
             << dynamic_cast<Movie*>(mediaInfo)->getTitle() << endl;
            
        return false;

    } else { 
        if (this->movie_type == MovieType::classic) {
            Classic* temp = dynamic_cast<Classic*>(mediaInfo);
            this->transactionLog += ' ' + temp->getTitle() + " by " + temp->getDirector();
            temp->IncrementStock(dynamic_cast<Classic*>(this->movie)->getMajorActor());
           
        } else {
            Movie* temp = dynamic_cast<Movie*>(mediaInfo);
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
