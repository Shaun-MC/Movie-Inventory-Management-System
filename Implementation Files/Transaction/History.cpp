#include "History.h"

History::History(){
    this->customerID = 0;
    this->commandType = CommandType::History;
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
bool History::historyProcess(CustomerList &customers){
    Customer *customerInfo;
    if(customers.retrieve(this->getCustomerID(), customerInfo)){
        cout << "History of " << this->getCustomerID() << " " << customerInfo->getName() << ':' << endl;

        //gethistory for customer.cpp that was uncommented
        if(customerInfo->getHistory().empty()){
            cout << " " << "History is Empty!" << endl;
        }else{
            for(int i = 0; i < customerInfo->getHistory().size(); i++){
                cout << " " << *customerInfo->getHistory().at(i) << endl;
            }
            return true;
        }
    }else{
        cerr << cerr << "Command, customer not found to show history:" << '\n' << "  " << this->entireTransaction << endl;
    }

    return false;
}

//need ostream?? 