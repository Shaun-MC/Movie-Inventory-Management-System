#ifndef BORROW_H
#define BORROW_H

#include "BorrowReturn.h"

class Borrow : public BorrowReturn {

 public:

  // Constructor - Destructor
  Borrow();
  ~Borrow();

  // Actions
  bool ProcessBorrow(MediaCollection &movies, CustomerCollection& customers);
};

#endif