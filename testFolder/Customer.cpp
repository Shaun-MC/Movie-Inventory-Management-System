#include "Customer.h"

// Constructors
Customer::Customer(){
    ID = 0;
    name = " ";
}

// Destructor
Customer::~Customer() { 
    for (int i = this->outstandingMedia.size() - 1; i >= 0; i--) {
        this->outstandingMedia[i] = nullptr;
    }
}

// Constructors
Customer::Customer(int ID, string name) {
    this->ID = ID;
    this->name = name;
}

// Copy Constructors
Customer::Customer(const Customer& rval) {
    this->ID = rval.ID;
    this->name = rval.name;
    this->history = rval.history;
    this->outstandingMedia = rval.outstandingMedia; 
}

// Return customer ID
int Customer::getID() const{
    return this->ID;
}

// Return customer name
string Customer::getName() const{
    return this->name;
}

// Set customer ID
void Customer::setID(int id){
    this->ID = id;
}

// Set customer name
void Customer::setName(string first, string last){ 
    this->name = first + " " + last;  
}

// Return transaction history
const vector<string>& Customer::getHistory() const{
    return this->history;
}

// Return outstanding media
const vector<Media*>& Customer::getOutstanding() const{
    return outstandingMedia;
}

// Add a new transaction to history
void Customer::AddHistory(string newTransaction){ 
    
    history.push_back(newTransaction);
}

// Add borrowed media to outstanding list
void Customer::BorrowMedia(Media* newMedia){ 
    outstandingMedia.push_back(newMedia);
}

// Return borrowed media
bool Customer::ReturnMedia(Media* oldMedia){ 
    bool ret = false;

    for (int i = 0; i < outstandingMedia.size(); i++) {
        if (*outstandingMedia[i] == *oldMedia) {
            outstandingMedia[i] = nullptr;
            outstandingMedia[i] = outstandingMedia.back();
            outstandingMedia.pop_back();
            ret = true;
            break;
        }
    }
    return ret;
}

// Comparison operator for less than
bool Customer::operator < (const Customer &rval) const {
    return this->ID < rval.ID;
}

// Comparison operator for equality
bool Customer::operator == (const Customer &rval) const {
    return this->ID == rval.ID;
}

// Overloaded output stream operator to print customer ID and name
ostream& operator << (ostream &ostrm, const Customer &obj){
    ostrm << obj.getID() << " " << obj.getName() << endl;
    return ostrm;
}
