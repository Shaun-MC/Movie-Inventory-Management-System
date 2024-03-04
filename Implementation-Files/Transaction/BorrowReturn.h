#ifndef BORROWRETURN_H
#define BORROWRETURN_H

#include "Transaction.h"

class BorrowReturn : public Transaction {

 public: 
  
  // Constructor - Destructor
  BorrowReturn();
  ~BorrowReturn();

  // Getter - Setter
  bool setData(ifstream &file);

 protected: 
  
  // Member Functions
  void processDrama(ifstream& moviedata, Media*& movie);
  void processClassic(ifstream& moviedata, Media*& movie);
  void processComedy(ifstream& moviedata, Media*& movie);
  void processInvalid(ifstream& file, const string& customer_id, const string& name);

  // Member Data
  MovieType movie_type; // char to MovieType
  MediaType Media_type; // char to MediaType

  Media* movie;
};

#include "Borrow.h"
#include "Return.h"

#endif