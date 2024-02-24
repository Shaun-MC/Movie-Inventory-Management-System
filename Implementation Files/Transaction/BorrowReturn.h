#ifndef BORROWRETURN_H
#define BORROWRETURN_H

#include "Transaction.h"

class BorrowReturn : public Command {

 public: 
  
  // Constructor - Destructor
  BorrowReturn();
  ~BorrowReturn();

  // Getter - Setter

 protected: 
  
  // Member Functions
  void processDrama(..., Stock*& stock);
  void processClassic(..., Stock*& stock);
  void processComedy(..., Stock*& stock);

  // Member Data
  char movie_type;
  string stock_type;

  Stock* stock;

};

#endif