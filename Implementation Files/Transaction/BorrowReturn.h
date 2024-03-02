#ifndef BORROWRETURN_H
#define BORROWRETURN_H

#include "Transaction.h"

// 
//NOT DONE YET WORKING ON IT 
// 

class BorrowReturn : public Command {

 public: 
  
  // Constructor - Destructor
  BorrowReturn();
  ~BorrowReturn();

  // Getter - Setter

 protected: 
  
  // Member Functions
  void processDrama(ifstream& moviedata, Stock*& stock);
  void processClassic(ifstream& moviedata, Stock*& stock);
  void processComedy(ifstream& moviedata, Stock*& stock);

  // Member Data
  MovieType movie_type; //char to MovieType
  MediaType stock_type; //string to  MediaType

  Stock* stock;

};

#endif