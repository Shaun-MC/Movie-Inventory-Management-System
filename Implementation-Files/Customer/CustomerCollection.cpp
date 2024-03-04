#include "CustomerCollection.h"

// Constructor
CustomerCollection::CustomerCollection() {}

// Getter
Customer* CustomerCollection::getCustomer(const int ID){
    
    return this->collection.getValue(ID);
}

// Actions
bool CustomerCollection::insert(const int ID, const string& name) { // UNTESTED
    
    Customer new_cust = Customer(ID, name);

    return this->collection.insertKeyValue(new_cust.getID(), new_cust);
}

bool CustomerCollection::retrieve(int key, Customer*& ret) { // UNTESTED
    
    return this->collection.retrieveValue(key, ret);
}

void CustomerCollection::receiveData(const string cust_line) { // UNTESTED

    int ID = 0;
    string name = "";

    this->parseCustomerLine(cust_line, ID, name);

    this->insert(ID, name);
}

// Private Member Function
void CustomerCollection::parseCustomerLine(const string line, int& key, string& name) const { // UNTESTED

    string f_name = "", l_name = "";

    stringstream parse(line);

    parse >> key;
    parse.ignore();

    parse >> l_name;
    parse.ignore();

    parse >> f_name;
    parse.ignore();

    name = f_name + " " + l_name;
}

void CustomerCollection::display() const {

    this->collection.display();
}



