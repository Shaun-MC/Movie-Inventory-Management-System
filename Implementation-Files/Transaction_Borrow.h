#ifndef TRANSACTION_BORROW_H
#define TRANSACTION_BORROW_H
#include "Transaction_BorrowReturn.h"

class Borrow : public BorrowReturn {
 public:
  // Constructor
  Borrow();

  // Destructor
  ~Borrow();

  // Actions
  bool ProcessBorrow(MediaCollection &movies, CustomerCollection& customers);
};

#endif