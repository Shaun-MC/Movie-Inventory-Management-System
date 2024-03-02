#ifndef BORROW_H
#define BORROW_H

#include "BorrowReturn.h"

class Borrow : public BorrowReturn {

 public:

  // Constructor - Destructor
  Borrow();
  ~Borrow();

  // Actions
  processBorrow(MediaCollection &movies, CustomerList& customers);

  // Operator Overloads 
};

#endif