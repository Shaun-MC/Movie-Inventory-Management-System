#include "CustomerCollection.h"

CustomerList::CustomerList(){

    // Nothing to do
}

Customer* CustomerList::getCustomer(int key){
    
    return this->customers.getValue(key);
}

bool CustomerList::insert(Customer &newCust){
    
    return this->customers.insertKeyValue(newCust.getID(), newCust);
}

bool CustomerList::retrieve(int key, Customer*& ret){
    
    return this->customers.retireveValue(key, ret);
}
