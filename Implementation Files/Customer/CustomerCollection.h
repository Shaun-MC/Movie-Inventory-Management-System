#ifndef CUSTOMERCOLLECTION_H
#define CUSTOMERCOLLECTION_H

#include "../Data Structures/HashTable.h"
#include "Customer.h"

class CustomerCollection {

 public: 

  // Constructor - Destructor
  CustomerCollection(); // Nessecary?

  // Getters - Setters
  Customer* getCustomer(int key);

  // Actions
  bool insert(Customer& newNode);
  
  bool retrieve(int key, Customer*& ret);
 
 private: 

  //AVLTree<Customer> list;
  HashTable<int, Customer> customers;

};

#endif