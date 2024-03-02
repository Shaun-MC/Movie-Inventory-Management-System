#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../Customer/CustomerCollection.h"
#include "../Stock/StockCollection.h"

#include <string>

struct CommandType {
  char Borrow = 'B';
  char Return = 'R';
  char History = 'H';
  char Inventory = 'I';
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