#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include "Media.h"
using namespace std;

// Size of the customer ID
const int kMinID = 1000;
const int kMaxID = 9999;

class Customer {
 public: 
  // Constructors
  Customer();
  Customer(int ID, string name);
  Customer(const Customer& rval);

  // Destructor
  ~Customer();

  // Getters - Setters
  int getID() const;
  string getName() const;
  void setID(int id);
  void setName(string first, string last);
  const vector<string> & getHistory() const;
  const vector<Media*> & getOutstanding() const;

  // Actions
  void AddHistory(string newTransaction);
  void BorrowMedia(Media* newMedia);
  bool ReturnMedia(Media* oldMedia);

  // Operator Overloads
  bool operator < (const Customer& rval) const;
  bool operator == (const Customer& rval) const;
  friend std::ostream& operator << (std::ostream& ostrm, const Customer& obj);
 
 private: 
  // Member Function
  int ID;
  string name; 
  vector<string> history; 
  vector<Media*> outstandingMedia;
};

#endif
