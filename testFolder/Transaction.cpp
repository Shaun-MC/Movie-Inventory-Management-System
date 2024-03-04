#include "Transaction.h"

Transaction::Transaction(){
    
    this->commandType = 0;
    this->customerID = 0;
    this->entireTransaction = " ";
}

Transaction::Transaction(const Transaction &other){
    
    this->commandType = other.commandType;
    this->customerID = other.customerID;
    this->entireTransaction = other.entireTransaction;
}

Transaction::~Transaction(){}

int Transaction::getCustomerID() const{
    return this->customerID;
}

char Transaction::getCommandType() const{
    return this->commandType;
}

// Assumes the sstream is pointing the cust ID
// Only commonality between transactions is the ID 
bool Transaction::setData(stringstream& trans_line) {

    int ID = 0;
    bool flag = true;
    
    trans_line >> ID;

    if (ID <= kMinID || ID >= kMaxID) {

        flag = false;
    } else {

        this->setCustomerID(ID);
    }

    return flag;
}

void Transaction::setCustomerID(int id){
    this->customerID = id;
}

void Transaction::setCommandType(char type){
    this->commandType = type;
}

void Transaction::process(MediaCollection &movies, CustomerCollection &customers){ // UNTESTED

    bool flag = false;

    switch (this->commandType) {
        
        case 'I':
        dynamic_cast<Inventory*>(this)->processInventory(movies);
        break;

        case 'H':
        flag = dynamic_cast<History*>(this)->processHistory(customers);
        break;

        case 'B':
        flag = dynamic_cast<Borrow*>(this)->processBorrow(movies, customers); 
        break;

        flag = dynamic_cast<Return*>(this)->processReturn(movies, customers);
        break;

        default:
        // Error Condition
        cerr << "Transaction::process() | No Command To Process" << endl;
        break;
    }

    if (!flag || this->commandType == CommandType::inventory || this->commandType == CommandType::history) {

        delete this;
    }
}
