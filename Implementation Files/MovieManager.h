#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H

#include <fstream>
#include <sstream>

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

  // Member Functions
  void parseCustomerLine(string line, int& key, string& f_name, string& l_name) const;
  
  CustomerList customers;
  StockCollection stocks;

  // queue<TransactionList>??
};

#endif