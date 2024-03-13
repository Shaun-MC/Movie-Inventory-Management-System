#include "Transaction.h"

// Constructors 
Transaction::Transaction(){
    
    this->commandType = this->customerID = 0;
    this->transactionLog = " ";
}

// Copy Constructors
Transaction::Transaction(const Transaction &other){
    
    this->commandType = other.commandType;
    this->customerID = other.customerID;
    this->transactionLog = other.transactionLog;
}

// Destructor
Transaction::~Transaction(){}

// Getter for customer ID
int Transaction::getCustomerID() const{
    return this->customerID;
}

// Getter for command type
char Transaction::getCommandType() const{
    return this->commandType;
}

// Set transaction data from stringstream 
bool Transaction::setData(stringstream& trans_line) {
    int ID = 0;
    bool flag = true;
    
    trans_line >> ID;

    if (ID < kMinID || ID > kMaxID) {
        flag = false;
    } 

    this->setCustomerID(ID); 

    return flag;
}

// Setter for customer ID
void Transaction::setCustomerID(int id){
    this->customerID = id;
}

// Setter for command type
void Transaction::setCommandType(char type){
    this->commandType = type;
}

// Process the transaction
void Transaction::Process(MediaCollection &movies, CustomerCollection &customers){ 
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
            cerr << "Transaction::process() | No Command To Process" << endl;
            break;
    }

    this->transactionLog.clear();

    delete this;
}
