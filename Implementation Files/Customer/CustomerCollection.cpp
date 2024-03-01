#include "CustomerCollection.h"

CustomerCollection::CustomerCollection() {}

Customer* CustomerCollection::getCustomer(int key){
    
    return this->customersCollection.getValue(key);
}

bool CustomerCollection::insert(const int ID, const string& name) {
    
    Customer new_cust = Customer(ID, name);

    return this->customersCollection.insertKeyValue(new_cust.getID(), new_cust);
}

bool CustomerCollection::retrieve(int key, Customer*& ret) {
    
    return this->customersCollection.retireveValue(key, ret);
}
