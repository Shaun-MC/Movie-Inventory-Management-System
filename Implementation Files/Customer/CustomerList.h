#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "../Data Structures/AVLTree.h"
#include "Customer.h"

class CustomerList {

 public: 

  // Constructor - Destructor
  CustomerList();

  ~CustomerList();

  // Getters - Setters
  bool getCustomer(int key);

  // Actions
  bool insert(int key, string f_name, string l_name);
  
  bool retrieve(int key, Customer& ret);
 
 private: 

  AVLTree<Customer> list;
};

#endif