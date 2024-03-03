#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

// 
//NOT DONE YET WORKING ON IT 
// 
#include "Transaction.h"
#include "Inventory.h"
#include "History.h"
#include "Borrow.h"
#include "Return.h"


class TransactionFactory {

 public:
  
  static Transaction* createTransaction(ifstream &file);

 private:

  static Transaction* createInventory(ifstream &file);

  static Transaction* createHistory(ifstream &file);

  static Transaction* createReturn(ifstream &file);

  static Transaction* createBorrow(ifstream &file);
}; 

#endif
