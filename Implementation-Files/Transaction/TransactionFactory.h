#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H
#include <sstream>
#include "Transaction.h"
#include "Inventory.h"
#include "History.h"
#include "Borrow.h"
#include "Return.h"

class TransactionFactory {

 public:
  // Create a transaction based on the provided transaction line
  static Transaction* CreateTransaction(const string trans_line); 

 private:
  // Create an inventory transaction
  static Transaction* CreateInventory(stringstream& trans_line);

  // Create a history transaction
  static Transaction* CreateHistory(stringstream& trans_line);

  // Create a return transaction
  static Transaction* CreateReturn(stringstream& trans_line);

  // Create a borrow transaction
  static Transaction* CreateBorrow(stringstream& trans_line);
}; 

#endif
