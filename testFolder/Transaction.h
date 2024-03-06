#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

#include "CustomerCollection.h"
#include "MediaCollection.h"

enum CommandType : char{
  
  borrow = 'B',
  return_ = 'R',
  history = 'H',
  inventory = 'I',
};

class Transaction {

 public: 
  
  // Constructors - Destructor 
  Transaction();
  Transaction(const Transaction &other);
  ~Transaction();

  // Getters - Setters
  int getCustomerID() const;
  char getCommandType() const;

  virtual bool setData(stringstream& trans_line);
  
  void setCustomerID(int id);
  void setCommandType(char type);

  // Actions
  virtual void Process (MediaCollection& movies, CustomerCollection& customers);

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