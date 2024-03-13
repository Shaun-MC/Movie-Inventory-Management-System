#ifndef BORROWRETURN_H
#define BORROWRETURN_H
#include "Transaction.h"

class BorrowReturn : public Transaction {
 public: 
  // Constructor
  BorrowReturn();

  // Destructor
  virtual ~BorrowReturn();

  // Getter - Setter
  bool setData(stringstream& trans_line);

 protected: 
  // Member Functions
  void ProcessDrama(stringstream& trans_line, Media*& newMedia);
  void ProcessClassic(stringstream& trans_line, Media*& newMedia);
  void ProcessComedy(stringstream& trans_line, Media*& newMedia);
  void ProcessInvalid(stringstream& trans_line, const int flag);

  // Member Data
  char media_type;
  char movie_type;
  Media* movie;
};

#include "Borrow.h"
#include "Return.h"

#endif