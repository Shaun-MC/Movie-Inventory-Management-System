#ifndef HASHTABLE_H
#define HASHTABLE_H

//Import
#include <iostream>
#include "Customer.h"
using namespace std;

// Size of the hash table
const int kTableSize = 103;

class HashTable {
 public: 

  // Constructor
  HashTable();

  // Destructor
  ~HashTable();

  // Get value associated with key
  Customer* getValue(const int key) const;

  // Actions
  bool InsertKeyValue(const int key, const Customer& val);
  bool RetrieveValue(const int key, Customer*& ret) const;
  void Display() const;
 
 protected: 
  // Hash functions
  int CreateHash(const int key) const;
  int DoubleHash(const int key) const;

  // Calculate hash functions
  int CalcHash(const int key) const;
  int CalcDoubleHash(const int key) const;

 private: 
  // Helper function to clear the hash table
  void Clear();
  
  // Array to hold the hash table
  Customer* table[kTableSize];

  // Current size of the hash table
  int curr_size;
};

#endif