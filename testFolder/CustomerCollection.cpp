#include "CustomerCollection.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
CustomerCollection::CustomerCollection() {}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Getter
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customer* CustomerCollection::getCustomer(const int ID){
    
    return this->collection.getValue(ID);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CustomerCollection::Insert(const int ID, const string& name) { // DONE
    
    Customer new_cust = Customer(ID, name);

    return this->collection.InsertKeyValue(new_cust.getID(), new_cust);
}

bool CustomerCollection::Retrieve(int key, Customer*& ret) { // UNTESTED
    
    return this->collection.RetrieveValue(key, ret);
}

void CustomerCollection::ReceiveData(const string cust_line) { // DONE

    int ID = 0;
    string name = "";

    this->ParseCustomerLine(cust_line, ID, name);

    this->Insert(ID, name);
}

void CustomerCollection::Display() const {

    this->collection.Display();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Function
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CustomerCollection::ParseCustomerLine(const string line, int& key, string& name) const { // DONE

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



