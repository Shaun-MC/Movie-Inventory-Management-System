#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <string>

#include "Media.h"

using namespace std;

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
  const vector<string> & getHistory() const;
  
  const vector<Media*> & getOutstanding() const;

  //Actions
  void addHistory(string newTransaction);

  void borrowMedia(Media* newMedia);
  bool returnMedia(Media* oldMedia);

  // Operator Overloads

  bool operator < (const Customer& rval) const;
  bool operator == (const Customer& rval) const;

  friend std::ostream& operator << (std::ostream& ostrm, const Customer& obj);
 
 private: 
 
  int ID;
  string name; 

  //uncomment for transaction
  vector<string> history; // error: expected expression
  vector<Media*> outstandingMedia;
};

#endif
