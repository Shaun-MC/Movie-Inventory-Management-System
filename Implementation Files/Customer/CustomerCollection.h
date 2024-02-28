#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "../Data Structures/HashTable.h"
#include "Customer.h"

class CustomerList {

 public: 

  // Constructor - Destructor
  CustomerList(); // Nessecary?

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