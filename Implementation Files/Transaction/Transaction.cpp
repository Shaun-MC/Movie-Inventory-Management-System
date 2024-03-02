#include "Transaction.h"

Transaction::Transaction(){
    this->commandType = " ";
    this->customerID = 0;
    this->entireTransaction = " ";

}

Transaction::Transaction(const Transaction &other){
    this->commandType = other.commandType;
    this->customerID = other.customerID;
    this->entireTransaction = other.entireTransaction;
}

Transaction::~Transaction(){
}

int Transaction::getCustomerID() const{
    return this->customerID;
}

char Transaction::getCommandType() const{
    return this->commandType;
}

void Transaction::setCustomerID(int id){
    this->customerID = id;
}

void Transaction::setCommandType(char type){
    this->commandType = type;
}


void Transaction::process(MediaCollection &movies, CustomerList &customers){

    bool process = false;

    if (this->commandType == Inventory) {
        dynamic_cast<Inventory*>(this)->processInventory(movies);

    } else if (this->commandType == Return) {
        process = dynamic_cast<Return*>(this)->processReturn(movies, customers);

    } else if (this->commandType == History) {
        process = dynamic_cast<History*>(this)->processHistory(customers);

    } else if (this->commandType == Borrow) {
        process = dynamic_cast<Borrow*>(this)->processBorrow(movies, customers);

    } else {
        cerr << "Command, nothing to process" << endl;
        process = false;
    }

    if (!process || this->commandType == History || this->commandType == Inventory) {
        delete this;
    }
}
