#include "CustomerCollection.h"

CustomerCollection::CustomerCollection() {}

Customer* CustomerCollection::getCustomer(int key){
    
    return this->customers.getValue(key);
}

bool CustomerCollection::insert(const int ID, const string& name) {
    
    Customer* new_cust = new Customer(ID, name);
    int test_ID = new_cust->getID();

    return this->customers.insertKeyValue(test_ID, *new_cust);

    delete new_cust;
}

bool CustomerCollection::retrieve(int key, Customer*& ret) {
    
    return this->customers.retireveValue(key, ret);
}
