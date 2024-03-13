#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H
#include <iostream>
#include <fstream>
#include "CustomerCollection.h"
#include "MediaCollection.h"
#include "MediaFactory.h"
#include "TransactionFactory.h"
using namespace std;

class MovieManager {
 public: 

  // Constructor
  MovieManager();
  ~MovieManager();
  
  // Actions
  void ReadCustomers(ifstream& customer_list);
  void ReadMovies(ifstream& movie_list);
  void ReadTransactions(ifstream& transaction_list);
  void DisplayCustomers() const;
  void DisplayMedia() const;
  
 private:
  // Private function
  CustomerCollection customers;
  MediaCollection stocks;
};

#endif