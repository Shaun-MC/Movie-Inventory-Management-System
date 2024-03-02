#include "Borrow.h"

Borrow::Borrow(){
}

Borrow::~Borrow(){
}

Borrow::processBorrow(MediaCollection &movies, CustomerList &customers){
    Customer *customerInfo;

    if(customerInfo.retrieve(this->getCustomerID(), customerinfo)){
        if(this->stock != nullptr){
            Media *mediaInfo = nullptr;

            if(movies.retrive(*this->stock, mediaInfo)){

                if(mediaInfo->reduceStock(1)){
                    customerInfo->borrowMedia(this->stock);

                    this->stock = nullptr;

                    mediaInfo->addHistory(this);
                    return true;
                }else{
                    cerr << "Command, media is out of stock:" << '\n' << "  " << this->entireTransaction << endl;
                }

            }else{
                cerr << "Command, media is not in media collection:" << '\n' << "  " << this->entireTransaction << endl;
            }
            
        }else{  
            cerr << "Command, this command doesn't contain media:" << '\n' << "  " << this->entireTransaction << endl;
        
        }
    }else{
        cerr << "Command, customer does not exist:" << '\n' << " " << this->entireTransaction << endl;
    }

    retrue false;
}

//need ostream?? 
