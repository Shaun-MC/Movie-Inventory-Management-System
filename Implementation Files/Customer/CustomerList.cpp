#include "CustomerCollection.h"

CustomerCollection::CustomerCollection(){

    // Nothing to do
}

Customer* CustomerCollection::getCustomer(int key){
    
    return this->customers.getValue(key);
}

bool CustomerCollection::insert(Customer &newCust){
    
    return this->customers.insertKeyValue(newCust.getID(), newCust);
}

bool CustomerCollection::retrieve(int key, Customer*& ret){
    
    return this->customers.retireveValue(key, ret);
}
