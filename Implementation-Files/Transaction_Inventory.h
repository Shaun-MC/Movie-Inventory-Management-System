#ifndef TRANSACTION_INVENTORY_H
#define TRANSACTION_INVENTORY_H
#include "Transaction.h"

class Inventory : public Transaction {
 public:
  
  // Constructor
  Inventory();

  // Destructor
  ~Inventory();

  // Actions 
  void ProcessInventory(MediaCollection& movies);
};

#endif