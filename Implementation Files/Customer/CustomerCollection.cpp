#include "CustomerCollection.h"

CustomerCollection::CustomerCollection() {}

Customer* CustomerCollection::getCustomer(int key){
    
    return this->collection.getValue(key);
}

bool CustomerCollection::insert(const int ID, const string& name) {
    
    Customer new_cust = Customer(ID, name);

    return this->collection.insertKeyValue(new_cust.getID(), new_cust);
}

bool CustomerCollection::retrieve(int key, Customer*& ret) {
    
    return this->collection.retrieveValue(key, ret);
}
