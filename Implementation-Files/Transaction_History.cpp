#include "Transaction_History.h"

// Constructor 
History::History(){
    this->customerID = 0;
    this->commandType = CommandType::history;
}

// Destructor
History::~History() {}

// Process the history of a customer
bool History::ProcessHistory(CustomerCollection &customers){
    Customer *customerInfo = nullptr;

    if (!customers.Retrieve(this->getCustomerID(), customerInfo)) {
        cerr << "History::ProcessHistory() | Customer " << this->getCustomerID() << " Does Not Exist" << endl;
        return false;
    }

    cout << endl << "History of " << customerInfo->getName() << ':' << endl;

    if (customerInfo->getHistory().empty()){
        cout << endl;
    } 

    const vector<string> cust_history = customerInfo->getHistory(); // Making a copy is unnessecary but fine for now

    for (int i = cust_history.size() - 1; i >= 0; i--) {
        cout << cust_history[i] << endl;
    }
    
    return true;
}