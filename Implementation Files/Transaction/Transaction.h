#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../Customer/CustomerCollection.h"
#include "../Stock/StockCollection.h"

#include <string>

class Transaction {

 public: 
  
  // Constructors 

  // Getters - Setters
  int getCustomerID() const;
  char getCommandType() const;
  string getEntireTransaction() const;

  void setCustomerID(int id);
  void setCommandType(char type);
  void setEntireTransaction() const; // Unsure of parameters atm

  // Actions
  virtual void process (StockCollection& movies, CustomerList& customers);

  // Operator Overloads
 
 protected:

  int customerID;
  char commandType;
  string entireTransaction;
};

#endif