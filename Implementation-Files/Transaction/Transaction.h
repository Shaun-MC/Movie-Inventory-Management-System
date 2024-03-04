#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

#include "../Customer/CustomerCollection.h"
#include "../Media/MediaCollection.h"

enum CommandType : char{
  
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

  virtual bool setData(stringstream& trans_line);
  
  void setCustomerID(int id);
  void setCommandType(char type);
  //void setEntireTransaction() const; // Unsure of parameters atm

  // Actions
  virtual void process (MediaCollection& movies, CustomerCollection& customers);

  // Operator Overloads
 
 protected:

  int customerID;
  char commandType;
  string entireTransaction;
};

#include "Inventory.h"
#include "History.h"
#include "BorrowReturn.h"

#endif