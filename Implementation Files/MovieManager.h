#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H

#include <iostream>
#include <fstream>

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

  void displayCustomers() const;
  void displayMedia() const;
  
 private:

  CustomerCollection customers;
  MediaCollection stocks;
};

#endif