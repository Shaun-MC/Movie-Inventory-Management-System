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

void Customer::setName(string first, string last){ 
    this->name = first + " " + last;  
}

//uncomment for transaction
const vector<string>& Customer::getHistory() const{ // UNTESTED
    
    return this->history;
}

const vector<Media*>& Customer::getOutstanding() const{ // UNTESTED
    
    return outstandingMedia;
}

void Customer::addHistory(string newTransaction){ // UNTESTED
    
    history.push_back(newTransaction);
}

bool Customer::borrowMedia(Media *newMedia){ // UNTESTED
    
    outstandingMedia.push_back(newMedia);
}

bool Customer::returnMedia(Media *oldMedia){ // UNTESTED
    
    bool ret = false;

    for (int i = 0; i < outstandingMedia.size(); i++) {

        if (*outstandingMedia[i] == *oldMedia) {

            delete outstandingMedia[i];
            outstandingMedia[i] = nullptr;

            *outstandingMedia[i] = *outstandingMedia.back();

            outstandingMedia.pop_back();

            ret = true;

            break;
        }
    }

    return ret;
}

bool Customer::operator < (const Customer &rval) const {
    
    return this->ID < rval.ID;
}

bool Customer::operator == (const Customer &rval) const {
    
    return this->ID == rval.ID;
}

ostream &operator<<(ostream &ostrm, const Customer &obj){
    
    ostrm << obj.getID() << " " << obj.getName() << endl;
    
    return ostrm;
}
