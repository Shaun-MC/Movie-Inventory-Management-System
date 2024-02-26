#ifndef RETURN_H
#define RETURN_H

#include "BorrowReturn.h"

class Return : public BorrowReturn {

 public: 

  // Constructors - Destructors
  Borrow();
  ~Borrow();

  // Actions
  bool processReturn(StockCollection& movies, CustomerCollection& customers);

  // Operator Overloads
};

#endif 