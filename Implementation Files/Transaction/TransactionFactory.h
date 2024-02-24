#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "Transaction.h"
#include "Inventory.h"
#include "History.h"
#include "Borrow.h"
#include "Return.h"


class TransactionFactory {

 public:
  
  static Transaction* createTransaction(...);

 private:

  static Transaction* createInventory(...);

  static Transaction* createHistory(...);

  static Transaction* createReturn(...);

  static Transaction* createBorrow(...);
}; 

#endif
