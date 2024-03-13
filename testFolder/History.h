#ifndef HISTORY_H
#define HISTORY_H 
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