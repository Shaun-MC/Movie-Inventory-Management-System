#ifndef HASHTABLE_H
#define HASHTABLE_H

const int kTableSize = 41;

// Used only as ints and customer* - CustomerCollection is a interface for Customers
template <typename Key, typename Value>
class HashTable {

 public: 

  // Constructor - Destructor
  HashTable();

  ~HashTable();

  // Getters - Setters
  Value* getValue(const Key& key) const;

  // Actions
  bool insertKeyValue(const Key key, const Value& val);

  bool retireveValue(const Key& key, Value*& ret) const;
 
 protected: 

  int createHash(const Key& key) const;
  int doubleHash(const int key) const;

  int calcHash(const Key& key) const;
  int calcDoubleHash(const int key) const;

 private: 
  
  void clear();
  
  Value* table[kTableSize];
  int curr_size;
};

// Constructor - Destructor
template <typename Key, typename Value>
HashTable<Key, Value>::HashTable() { // DONE

    for (int i = 0; i < kTableSize; i++) {

        this->table[i] = nullptr;
    }

    this->curr_size = 0;
}

template <typename Key, typename Value>
HashTable<Key, Value>::~HashTable() {

    this->clear();
}

// Getters - Setters
template <typename Key, typename Value>
Value* HashTable<Key, Value>::getValue(const Key& key) const {

    // Get the hash value
    const int hash = createHash(key);
    
    // Check value
    if (hash < 0 || hash > kTableSize) { // Possible Error Condition

        return nullptr;
    }

    // Index array - Return the value at the index
    return this->table[hash];
}

// Actions
template <typename Key, typename Value>
bool HashTable<Key, Value>::insertKeyValue(const Key key, const Value& val) {

    // How does it handle duplicates - have to pass in val by reference to check compare values

    // Get the hash value
    const int hash = createHash(key);

    // Check the value
    if (hash < 0 || hash >= kTableSize) {

        return false;
    } else { // Viable locations - point the table ptr to the val

        this->table[hash] = new Value(val); // int obj cannot be deleted before the pointer is, lose the reference
        
        ++this->curr_size;
        
        return true;
    }  
}

template <typename Key, typename Value>
bool HashTable<Key, Value>::retireveValue(const Key& key, Value*& ret) const {
    
    const int hash = calcHash(key);

    if (hash < 0 || hash >= kTableSize || 
        this->table[hash] == nullptr) {

        return false;
    } else {

        if (ret != nullptr) {

            delete ret;
            ret = nullptr;
        }

        ret = new Value();
        *ret = *this->table[hash];

        return true;
    }
}

// Protected Member Functions
template <typename Key, typename Value>
int HashTable<Key, Value>::createHash(const Key& key) const {

    // Will only ever be an int, just for safety
    //int insertion_key = reinterpret_cast<int>(key);

    const int firstHashVal = calcHash(key);

    return (this->table[firstHashVal] == nullptr) ? firstHashVal : doubleHash(key);
}

template <typename Key, typename Value>
int HashTable<Key, Value>::doubleHash(const int insertion_key) const {

    // IDEA: Implement a counter to protected against infinite loops

    const int increment_curr_size = calcDoubleHash(insertion_key);
    
    int dHashVal = calcDoubleHash(insertion_key);

    while (this->table[dHashVal] != nullptr) {

        dHashVal += increment_curr_size;
    }

    return dHashVal;
}

template <typename Key, typename Value>
int HashTable<Key, Value>::calcHash(const Key& key) const {

    return key % kTableSize;
}

template <typename Key, typename Value>
int HashTable<Key, Value>::calcDoubleHash(const int insertion_key) const {

    return kTableSize - (insertion_key % kTableSize);
}

// Private Memeber Functions
template <typename Key, typename Value>
void HashTable<Key, Value>::clear() {

    for (int i = 0; i < kTableSize; i++) {

        if (this->table[i] == nullptr) {

            continue;
        } else {

            delete this->table[i];
            this->table[i] = nullptr;
        }
    }
}

#endif