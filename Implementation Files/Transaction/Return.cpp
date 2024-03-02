#include "Return.h"

Return::Return(){
}

Return::~Return(){
}

bool Return::processReturn(MediaCollection &movies, CustomerCollection &customers){
    
    Customer *customerInfo;

    if(customerInfo.retrieve(this->getCustomerID(), customerinfo)){
        if(this->stock != nullptr){
            Media *mediaInfo = nullptr;

            if(movies.retrive(*this->stock, mediaInfo)){
                if(customerInfo->returnMedia(this->stock)){
                    delete this->stock;

                    mediaInfo->addStock(1);

                    mediaInfo->addHistory(this);
                    return true;
                }
            }else{
                cerr << "Command, this command doesn't contain media:" << '\n' << " " << this->entireTransaction << endl;
            }
        }
    }else{
        cerr << "Command, customer does not exist:" << '\n' << " " << this->entireTransaction << endl;
    }

    return false;
}

//need to add ostream?? 
