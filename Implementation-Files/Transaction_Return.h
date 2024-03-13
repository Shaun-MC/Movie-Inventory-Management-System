#ifndef TRANSACTION_RETURN_H
#define TRANSACTION_RETURN_H
#include "Transaction_BorrowReturn.h"
  
class Return : public BorrowReturn {
 public: 
  // Constructors 
  Return();

  // Destructors
  ~Return();

  // Actions
  bool ProcessReturn(MediaCollection& movies, CustomerCollection& customers);
};

#endif 