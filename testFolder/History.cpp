#include "History.h"

History::History(){
    
    this->customerID = 0;
    this->commandType = CommandType::history;
}

History::~History() {}

bool History::processHistory(CustomerCollection &customers){ // UNTESTED
    
    Customer *customerInfo;

    if (!customers.retrieve(this->getCustomerID(), customerInfo)) {

        // Run Time Error Condition
        cerr << "History::historyProcess() | Customer " << this->getCustomerID() << " Does Not Exist" << endl;
        return false;
    }

    cout << "History of " << this->getCustomerID() << " " << customerInfo->getName() << ':' << endl;

    if (customerInfo->getHistory().empty()){
        
        // NOT an Error Condition
        cout << " " << "History is Empty!" << endl;
    } else {

        for (string trans : customerInfo->getHistory()) {

            cout << " " << trans << endl;
        }

        return true;
    }

    return false;
}

//need ostream?? 