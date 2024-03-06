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
  void ProcessDrama(stringstream& trans_line);
  void ProcessClassic(stringstream& trans_line);
  void ProcessComedy(stringstream& trans_line);

  void ProcessInvalid(stringstream& trans_line);

  // Member Data
  Media* movie;

};

#include "Borrow.h"
#include "Return.h"

#endif