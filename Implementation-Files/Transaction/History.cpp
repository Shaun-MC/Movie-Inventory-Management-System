#include "History.h"

History::History(){
    
    this->customerID = 0;
    this->commandType = CommandType::history;
}

History::~History(){
}

bool History::setHistoryData(ifstream &file){
    
    file.ignore();
    file >> this->customerID;
    
    if(file.fail()){
        cout << "Customer ID is Invalid" << endl;
        file.clear();
        file.ignore(0, '\n'); //0?
        return false;
    }

    return true;
}

//change void to bool and removed StockCollection &movies getHistory()
bool History::processHistory(CustomerCollection &customers){
    
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
        
        // TODO: Really don't want to make a new copy - look into
        const vector<string> temp = customerInfo->getHistory();

        for (string trans : temp) {

            cout << " " << trans << endl;
        }

        return true;
    }

    return false;
}

//need ostream?? 