#ifndef HASHTABLE_H
#define HASHTABLE_H

// Warning : Unable to process IntelliSense for file with same canonicalized path as existing file.
#include <iostream>

#include "Customer.h"

using namespace std;

const int kTableSize = 101;

class HashTable {

 public: 

  // Constructor - Destructor
  HashTable();

  ~HashTable();

  // Getters - Setters
  Customer* getValue(const int key) const;

  // Actions
  bool InsertKeyValue(const int key, const Customer& val);

  bool RetrieveValue(const int key, Customer*& ret) const;

  void Display() const;
 
 protected: 

  int CreateHash(const int key) const;
  int DoubleHash(const int key) const;

  int CalcHash(const int key) const;
  int CalcDoubleHash(const int key) const;

 private: 
  
  void Clear();
  
  Customer* table[kTableSize];
  int curr_size;
};

#endif