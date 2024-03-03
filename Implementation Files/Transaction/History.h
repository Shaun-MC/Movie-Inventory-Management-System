#ifndef HISTORY_H
#define HISTORY_H 

#include "Transaction.h"

class History : public Transaction {

 public: 
  
  // Constructor - Destructor
  History();
  ~History();

  //Setter
  bool setHistoryData(ifstream& file);

  // Actions
  bool processHistory(CustomerCollection& customers);

  // Operator Overloads
};

#endif