#ifndef RETURN_H
#define RETURN_H
#include "BorrowReturn.h"
  
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