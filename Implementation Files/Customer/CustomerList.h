#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "../AVLTree.h"
#include "../Customer/Customer.h"

class CustomerList {

 public: 

  // Constructor - Destructor
  CustomerList();

  ~CustomerList();

  // Getters - Setters
  bool getCustomer(int key);

  // Actions
  bool insert(Customer& newNode);
  
  bool retrieve(int key, Customer& ret);
 
 private: 

  AVLTree<Customer> list;
}