#include "Return.h"

Return::Return(){
}

Return::~Return(){
}

bool Return::processReturn(MediaCollection &movies, CustomerCollection &customers){ // UNTESTED
    
    Customer* customerInfo = nullptr;
    Media* mediaInfo = nullptr;

    if (!customers.retrieve(this->getCustomerID(), customerInfo)) {

        // Run Time Error Condition
        cerr << "Return::processReturn() | Customer " << this->getCustomerID() << " Does Not Exist" << endl;  
        return false;
    }

    if (this->movie == nullptr || movies.retrieve(this->movie, mediaInfo)) {
        
        // Run Time Error Condition
        cerr << "Return::processReturn() | Current Transaction Does Not Have an Associated Media" << endl;
        return false;
    }

    if (customerInfo->returnMedia(this->movie)) {

        // Run Time Error Condition
        cerr << "Return::processReturn() | Customer " << this->getCustomerID() << " Never Checked Out " << 
             dynamic_cast<Movie*>(this->movie)->getTitle() << endl;
    } else {

        delete this->movie;
        this->movie = nullptr;

        mediaInfo->incrementStock();
        customerInfo->addHistory(this);

        return true;
    }

    return false;
}

//need to add ostream?? 
