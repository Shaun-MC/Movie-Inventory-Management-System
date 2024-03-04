#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "Transaction.h"
#include "Inventory.h"
#include "History.h"
#include "Borrow.h"
#include "Return.h"


class TransactionFactory {

 public:
  
  static Transaction* createTransaction(ifstream &file); //change const string trans_line to ifstream

 private:

  static Transaction *createInventory(ifstream &file);

  static Transaction *createHistory(ifstream &file);

  static Transaction *createReturn(ifstream &file);

  static Transaction *createBorrow(ifstream &file);
}; 

#endif
