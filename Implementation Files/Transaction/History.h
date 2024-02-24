#ifndef HISTORY_H
#define HISTORY_H 

#include "Transaction.h"

class History : public Transaction {

 public: 
  
  // Constructor - Destructor
  History();
  ~History();

  // Getter - Setter

  // Actions
  void setHistoryData(...); // ??

  void historyProcess(StockCollection& movies, CustomerList& customers);

  // Operator Overloads
};

#endif