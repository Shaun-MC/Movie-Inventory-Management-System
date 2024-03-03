#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H

#include <string>

#include "../Data Structures/HashTable.h"
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

  void receiveData(const string cust_line); 
 
 private: 

  void parseCustomerLine(const string line, int& key, string& name) const;

  HashTable<int, Customer> collection;
};

#endif