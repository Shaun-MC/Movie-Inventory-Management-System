#ifndef HISTORY_H
#define HISTORY_H 

#include "Transaction.h"

class History : public Transaction {

 public: 
  
  // Constructor - Destructor
  History();
  ~History();

  // Actions
  bool ProcessHistory(CustomerCollection& customers);

  // Operator Overloads
};

#endif