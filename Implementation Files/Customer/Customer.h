#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>

#include "../Stock/Stock.h"
#include "../Transaction/Transaction.h"

const int kMinID = 1000;
const int kMaxID = 9999;

class Customer {

 public: 

  // Constructor
  Customer();

  // Getters - Setters
  int getID() const;
  string getName() const;

  void setID(int id);
  void setName(string first, string last);

  vector<Transaction*> & getHistory() const;
  
  vector<Media*> & getOutstanding() const;

  // Actions

  void addHistory(Transaction* newTransaction);

  bool borrowMedia(Media* newMedia);
  bool returnMedia(Media* oldMedia);
  
  // Operator Overloads

  bool operator < (const Customer& rval) const;
  bool operator == (const Customer& rval) const;

  friend ostream& operator << (ostream& ostrm, const Customer& obj);
 
 private: 
 
  int ID;
  string name;

  vector<Transaction*> transaction_history;
  vector<Media*> outstandingMedia;
};

#endif


 // Constructor - Destructor

 // Getters - Setters

 // Actions

 // Operator Overloads
