#include "DS_HashTable.h"

// Constructor
HashTable::HashTable() {
    for (int i = 0; i < kTableSize; i++) {
        this->table[i] = nullptr;
    }

    this->curr_size = 0;
}

// Destructor
HashTable::~HashTable() {
    this->Clear();
}

// Get value associated with a key
Customer* HashTable::getValue(const int key) const { 
    const int hash = CreateHash(key);

    if (hash < 0 || hash > kTableSize) { 
        return nullptr;
    }

    return this->table[hash];
}

// Insert key-value pair into the hash table
bool HashTable::InsertKeyValue(const int key, const Customer& val) { 
    const int hash = CreateHash(key);

    if (hash < 0 || hash >= kTableSize) {
        return false;

    } else { 
        this->table[hash] = new Customer(val);
        ++this->curr_size;
        return true;
    }  
}

// Retrieve value associated with a key
bool HashTable::RetrieveValue(const int key, Customer*& ret) const { 
    const int hash = CalcHash(key);

    if (hash < 0 || 
        hash >= kTableSize || 
        this->table[hash] == nullptr) {

        return false;
    } else {

        if (ret != nullptr) {

            delete ret;
            ret = nullptr;
        }

        ret = this->table[hash];

        return true;
    }
}

// Display the hash table
void HashTable::Display() const {
    for (int i = 0; i < kTableSize; i++) {
        if(this->table[i] != nullptr) {
            cout << *this->table[i];
        }
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Protected Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Create primary hash value
int HashTable::CreateHash(const int key) const { 
    const int firstHashVal = CalcHash(key);
    return (this->table[firstHashVal] == nullptr) ? firstHashVal : DoubleHash(key);
}

// Calculate primary hash value
int HashTable::CalcHash(const int key) const {
    return key % kTableSize;
}

// Calculate primary hash value
int HashTable::CalcDoubleHash(const int insertion_key) const { 
    return kTableSize - (insertion_key % kTableSize);
}

// Secondary hash function
int HashTable::DoubleHash(const int insertion_key) const {
    const int increment_curr_size = CalcDoubleHash(insertion_key);
    int dHashVal = CalcDoubleHash(insertion_key);

    while (this->table[dHashVal] != nullptr) {
        dHashVal += increment_curr_size;
    }

    return dHashVal;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Clear the hash table
void HashTable::Clear() { 
    for (int i = 0; i < kTableSize; i++) {
        if (this->table[i] == nullptr) {
            continue;

        } else {
            delete this->table[i];
            this->table[i] = nullptr;
        }
    }
}


