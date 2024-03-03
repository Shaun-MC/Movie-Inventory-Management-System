#ifndef RETURN_H
#define RETURN_H

#include "BorrowReturn.h"

  //need ostream?? 
  
class Return : public BorrowReturn {

 public: 

  // Constructors - Destructors
  Return();
  ~Return();

  // Actions
  bool processReturn(MediaCollection& movies, CustomerCollection& customers);

  // Operator Overloads
};

#endif 