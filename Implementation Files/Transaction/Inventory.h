#ifndef INVENTORY_H
#define INVENTORY_H

#include "Transaction.h"

class Inventory : public Transaction {

 public:
  
  // Constructor - Destructor
  Inventory();
  ~Invenotory();

  // Actions 
  void inventoryProcess(StockCollection& movies);

  // Operator Overloads

}