#include "Customer.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructors
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customer::Customer(){
    
    ID = 0;
    name = " ";
}

Customer::~Customer() { // No changes in memory leak

    for (int i = this->outstandingMedia.size() - 1; i >= 0; i--) {

        delete this->outstandingMedia[i];
        this->outstandingMedia[i] = nullptr;

        this->outstandingMedia.pop_back();
    }
}

Customer::Customer(int ID, string name) {

    this->ID = ID;
    this->name = name;
}

Customer::Customer(const Customer& rval) {

    this->ID = rval.ID;
    this->name = rval.name;

    this->history = rval.history;
    this->outstandingMedia = rval.outstandingMedia; // Don't know if it'll be a deep copy
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Getters - Setters
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

const vector<string>& Customer::getHistory() const{ // UNTESTED
    
    return this->history;
}

const vector<Media*>& Customer::getOutstanding() const{ // UNTESTED
    
    return outstandingMedia;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Customer::AddHistory(string newTransaction){ // UNTESTED
    
    history.push_back(newTransaction);
}

void Customer::BorrowMedia(Media* newMedia){ // UNTESTED
    
    outstandingMedia.push_back(newMedia);
}

bool Customer::ReturnMedia(Media*& oldMedia){ // UNTESTED
    
    bool ret = false;

    for (int i = 0; i < outstandingMedia.size(); i++) {

        if (*outstandingMedia[i] == *oldMedia) {

            delete outstandingMedia[i];
            outstandingMedia[i] = nullptr;

            outstandingMedia[i] = outstandingMedia.back();

            outstandingMedia.pop_back();

            ret = true;

            break;
        }
    }

    return ret;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Operator Overloads
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Customer::operator < (const Customer &rval) const {
    
    return this->ID < rval.ID;
}

bool Customer::operator == (const Customer &rval) const {
    
    return this->ID == rval.ID;
}

ostream& operator << (ostream &ostrm, const Customer &obj){
    
    ostrm << obj.getID() << " " << obj.getName() << endl;
    
    return ostrm;
}
