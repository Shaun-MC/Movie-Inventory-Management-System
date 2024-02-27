#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H

#include <fstream>

#include "../Customer/CustomerList.h"
#include "../Stock/StockCollection.h"

class MovieManager {

 public: 

  // Constructor
  MovieManager();
  
  // Actions
  void ReadCustomers(ifstream& ifile);
  void ReadMovies(ifstream& ifile);
  void ReadTransactions(ifstream& ifile);
  
 private:
  
  CustomerList customers;
  StockCollection stocks;

  // queue<TransactionList>??
};

#endif