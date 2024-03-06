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
  
  static Transaction* CreateTransaction(const string trans_line); 

 private:

  static Transaction *CreateInventory(stringstream& trans_line);

  static Transaction *CreateHistory(stringstream& trans_line);

  static Transaction *CreateReturn(stringstream& trans_line);

  static Transaction *CreateBorrow(stringstream& trans_line);
}; 

#endif
