#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H

#include <sstream>

#include "HashTable.h"

// Warning: Unable to process IntelliSense for file with same canonicalized path as existing file.

using namespace std;

class CustomerCollection {

 public: 

  // Constructor
  CustomerCollection(); 

  // Getters - Setters
  Customer* getCustomer(int key);

  // Actions
  bool Insert(const int ID, const string& name);
  
  bool Retrieve(int key, Customer*& ret);

  void ReceiveData(const string cust_line); 

  void Display() const;
 
 private: 

  // Member Function
  void ParseCustomerLine(const string line, int& key, string& name) const;

  // Member Data
  HashTable collection;
};

#endif