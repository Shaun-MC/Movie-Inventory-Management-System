#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../Customer/CustomerCollection.h"
#include "../Media/MediaCollection.h"

#include <string>

enum CommandType : char {
  
  borrow = 'B',
  return_ = 'R',
  history = 'H',
  inventory = 'I',
};

class Transaction {

 public: 
  
  // Constructors 
  Transaction();
  Transaction(const Transaction &other);
  ~Transaction();

  // Getters - Setters
  int getCustomerID() const;
  char getCommandType() const;
  //string getEntireTransaction() const;

  void setCustomerID(int id);
  void setCommandType(char type);
  //void setEntireTransaction() const; // Unsure of parameters atm

  // Actions
  virtual void process (MediaCollection& movies, CustomerList& customers);

  // Operator Overloads
 
 protected:

  int customerID;
  CommandType commandType;
  string entireTransaction;
};

#endif