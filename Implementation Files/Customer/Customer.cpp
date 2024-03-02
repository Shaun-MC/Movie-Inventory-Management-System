#include "Customer.h"

Customer::Customer(){
    ID = 0;
    name = " ";
}

Customer::Customer(int ID, string name) {

    this->ID = ID;
    this->name = name;
}

int Customer::getID() const{
    return this->ID;
}

string Customer::getName() const{
    return this->name;
}

void Customer::setID(int id){
    this->ID = id;
}

void Customer::setName(string first, string last){ //??
    this->name = first + " " + last;  
}

//uncomment for transaction
vector<Transaction*>& Customer::getHistory() const{
    return transaction_history;
}

vector<Media *>& Customer::getOutstanding() const{
    return outstandingMedia;
}

void Customer::addHistory(Transaction *newTransaction){
    transaction_history.push_back(newTransaction);
}

bool Customer::borrowMedia(Media *newMedia){
    outstandingMedia.push_back(newMedia);
}

bool Customer::returnMedia(Media *oldMedia){
    for(size_t i = 0; i <= outstandingMedia.size(); i++){
        
        if(*outstandingMedia[i] == oldMedia){
            
            delete outstandingMedia[i];
            
            outstandingMedia[i] = outstandingMedia.back();
            
            outstandingMedia[i].pop_back();
            
            return true;
        }
    }
    return false;
}
//until here

bool Customer::operator<(const Customer &rval) const{
    
    return this->ID < rval.ID;
}

bool Customer::operator==(const Customer &rval) const{
    
    return this->ID == rval.ID;
}

ostream &operator<<(ostream &ostrm, const Customer &obj){
    
    ostrm << obj.getID() << " " << obj.getName() << endl;
    return ostrm;
}
