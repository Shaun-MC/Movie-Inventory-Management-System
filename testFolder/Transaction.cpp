#include "Transaction.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructors - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Transaction::Transaction(){
    
    this->commandType = this->customerID = 0;
    this->transactionLog = " ";
}

Transaction::Transaction(const Transaction &other){
    
    this->commandType = other.commandType;
    this->customerID = other.customerID;
    this->transactionLog = other.transactionLog;
}

Transaction::~Transaction(){}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Getters - Setters
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

    if (ID < kMinID || ID > kMaxID) {

        flag = false;
    } /*else {

       this->setCustomerID(ID);
    }*/

    this->setCustomerID(ID); // Bad practice - intentionally storing bad data

    return flag;
}

void Transaction::setCustomerID(int id){
    this->customerID = id;
}

void Transaction::setCommandType(char type){
    this->commandType = type;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Transaction::Process(MediaCollection &movies, CustomerCollection &customers){ // UNTESTED

    bool flag = false;

    switch (this->commandType) {
        
        case CommandType::inventory :
        dynamic_cast<Inventory*>(this)->ProcessInventory(movies);
        break;

        case CommandType::history :
        flag = dynamic_cast<History*>(this)->ProcessHistory(customers);
        break;

        case CommandType::borrow :
        flag = dynamic_cast<Borrow*>(this)->ProcessBorrow(movies, customers); 
        break;

        case CommandType::return_ :
        flag = dynamic_cast<Return*>(this)->ProcessReturn(movies, customers);
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
