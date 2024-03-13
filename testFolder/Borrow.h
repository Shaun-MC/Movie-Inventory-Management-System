#ifndef BORROW_H
#define BORROW_H
#include "BorrowReturn.h"

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