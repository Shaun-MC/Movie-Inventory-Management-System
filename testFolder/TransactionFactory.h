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
  
  static Transaction* createTransaction(const string trans_line); 

 private:

  static Transaction *createInventory(stringstream& trans_line);

  static Transaction *createHistory(stringstream& trans_line);

  static Transaction *createReturn(stringstream& trans_line);

  static Transaction *createBorrow(stringstream& trans_line);
}; 

#endif
