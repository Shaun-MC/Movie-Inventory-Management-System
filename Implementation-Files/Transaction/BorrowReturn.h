#ifndef BORROWRETURN_H
#define BORROWRETURN_H

#include "Transaction.h"

// 
//NOT DONE YET WORKING ON IT 
// 

class BorrowReturn : public Transaction {

 public: 
  
  // Constructor - Destructor
  BorrowReturn();
  ~BorrowReturn();

  // Getter - Setter

 protected: 
  
  // Member Functions
  void processDrama(ifstream& moviedata, Media*& movie);
  void processClassic(ifstream& moviedata, Media*& movie);
  void processComedy(ifstream& moviedata, Media*& movie);

  // Member Data
  MovieType movie_type; // char to MovieType
  MediaType Media_type; // char to MediaType

  Media* movie;
};

#endif