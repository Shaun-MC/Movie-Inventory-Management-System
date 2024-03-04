#ifndef BORROWRETURN_H
#define BORROWRETURN_H

#include "Transaction.h"

class BorrowReturn : public Transaction {

 public: 
  
  // Constructor - Destructor
  BorrowReturn();
  ~BorrowReturn();

  // Getter - Setter
  bool setData(stringstream& trans_line);

 protected: 
  
  // Member Functions
  void processDrama(stringstream& trans_line);
  void processClassic(stringstream& trans_line);
  void processComedy(stringstream& trans_line);

  void processInvalid(stringstream& trans_line);

  // Member Data

  Media* movie;
};

#include "Borrow.h"
#include "Return.h"

#endif