#include "CustomerCollection.h"

// Constructor
CustomerCollection::CustomerCollection() {}

// Get a customer from the collection by ID
Customer* CustomerCollection::getCustomer(const int ID){
    return this->collection.getValue(ID);
}

// Insert a new customer into the collection
bool CustomerCollection::Insert(const int ID, const string& name) { 
    Customer new_cust = Customer(ID, name);
    return this->collection.InsertKeyValue(new_cust.getID(), new_cust);
}

// Retrieve a customer from the collection by key
bool CustomerCollection::Retrieve(int key, Customer*& ret) { 
    return this->collection.RetrieveValue(key, ret);
}

// Parse customer data from a line and insert it into the collection
void CustomerCollection::ReceiveData(const string cust_line) {
    int ID = 0;
    string name = "";

    this->ParseCustomerLine(cust_line, ID, name);
    this->Insert(ID, name);
}

// Display all customers in the collection
void CustomerCollection::Display() const {
    this->collection.Display();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Function
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Parse a line containing customer data into ID and name
void CustomerCollection::ParseCustomerLine(const string line, int& key, string& name) const { 
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



