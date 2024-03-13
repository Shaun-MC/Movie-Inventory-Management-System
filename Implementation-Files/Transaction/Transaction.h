#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include "CustomerCollection.h"
#include "MediaCollection.h"

// Enumeration for CommandType types
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

  // Copy Constructors
  Transaction(const Transaction &other);

  // Destructor
  virtual ~Transaction();

  // Getters - Setters
  int getCustomerID() const;
  char getCommandType() const;
  virtual bool setData(stringstream& trans_line);
  void setCustomerID(int id);
  void setCommandType(char type);

  // Actions
  virtual void Process(MediaCollection& movies, CustomerCollection& customers);
  
 protected:
  // Protected varibles
  int customerID;
  char commandType;
  string transactionLog;
};

#include "Inventory.h"
#include "History.h"
#include "BorrowReturn.h"

#endif