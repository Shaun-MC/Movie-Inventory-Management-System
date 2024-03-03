#ifndef INVENTORY_H
#define INVENTORY_H

#include "Transaction.h"

class Inventory : public Transaction {

 public:
  
  // Constructor - Destructor
  Inventory();
  ~Inventory();

  // Actions 
  bool processInventory(MediaCollection& movies);

  // Operator Overloads

};

#endif