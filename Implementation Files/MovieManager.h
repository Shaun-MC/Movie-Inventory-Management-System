#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "CustomerCollection.h"
#include "MediaCollection.h"

using namespace std;

class MovieManager {

 public: 

  // Constructor
  MovieManager();
  
  // Actions
  void ReadCustomers(ifstream& customer_list);
  void ReadMovies(ifstream& movie_list);
  void ReadTransactions(ifstream& transaction_list);

  void display() const;
  
 private:

  // Member Functions
  void parseCustomerLine(const string line, int& key, string& name) const;
  
  CustomerCollection* customers;
  MediaCollection stocks;
};

#endif