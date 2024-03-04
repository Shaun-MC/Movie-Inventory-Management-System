#ifndef BORROW_H
#define BORROW_H

#include "BorrowReturn.h"

class Borrow : public BorrowReturn {

 public:

  // Constructor - Destructor
  Borrow();
  ~Borrow();

  // Actions
  bool processBorrow(MediaCollection &movies, CustomerCollection& customers);

  // Operator Overloads 
};

#endif