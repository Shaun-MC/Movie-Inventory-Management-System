#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "../Media/Media.h"
#include "../Transaction/Transaction.h"

const int kMinID = 1000;
const int kMaxID = 9999;

class Customer {

 public: 

  // Constructor
  Customer();
  Customer(int ID, string name);

  // Getters - Setters
  int getID() const;
  string getName() const;

  void setID(int id);
  void setName(string first, string last);

  //uncomment for transaction
  vector<Transaction*> & getHistory() const;
  
  vector<Media*> & getOutstanding() const;

  //Actions

  void addHistory(Transaction* newTransaction);

  bool borrowMedia(Media* newMedia);
  bool returnMedia(Media* oldMedia);
  //until here

  // Operator Overloads

  bool operator<(const Customer& rval) const;
  bool operator==(const Customer& rval) const;

  friend std::ostream& operator << (std::ostream& ostrm, const Customer& obj);
 
 private: 
 
  int ID;
  string name; 

  //uncomment for transaction
  vector<Transaction*> transaction_history;
  vector<Media*> outstandingMedia;
};

#endif
