#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H

#include <string>

#include "HashTable.h"
#include "Customer.h"

using namespace std;

class CustomerCollection {

 public: 

  // Constructor
  CustomerCollection(); 

  // Getters - Setters
  Customer* getCustomer(int key);

  // Actions
  bool insert(const int ID, const string& name);
  
  bool retrieve(int key, Customer*& ret);
 
 private: 

  HashTable<int, Customer> customersCollection;
};

#endif