#ifndef TRANSACTION_HISTORY_H
#define TRANSACTION_HISTORY_H 
#include "Transaction.h"

class History : public Transaction {
 public: 
  // Constructor
  History();

  // Destructor
  ~History();

  // Actions
  bool ProcessHistory(CustomerCollection& customers);
};

#endif