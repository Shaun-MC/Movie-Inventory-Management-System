#include "HashTable.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
HashTable::HashTable() {

    for (int i = 0; i < kTableSize; i++) {

        this->table[i] = nullptr;
    }

    this->curr_size = 0;
}

HashTable::~HashTable() {

    this->Clear();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Getters - Setters
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customer* HashTable::getValue(const int key) const { // UNTESTED

    // Get the hash value
    const int hash = CreateHash(key);
    
    // Check value
    if (hash < 0 || hash > kTableSize) { // Possible Error Condition

        return nullptr;
    }

    // Index array - Return the value at the index
    return this->table[hash];
}

bool HashTable::InsertKeyValue(const int key, const Customer& val) { // FINE

    // How does it handle duplicates - have to pass in val by reference to check compare values

    // Get the hash value
    const int hash = CreateHash(key);

    // Check the value
    if (hash < 0 || hash >= kTableSize) {

        return false;
    } else { // Viable locations - point the table ptr to the val

        // 1 | 12 of these doesn't get deleted 
        this->table[hash] = new Customer(val); // int obj cannot be deleted before the pointer is, lose the reference
        
        ++this->curr_size;
        
        return true;
    }  
}

bool HashTable::RetrieveValue(const int key, Customer*& ret) const { // UNTESTED
    
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

void HashTable::Display() const { // DONE

    for (int i = 0; i < kTableSize; i++) {

        if(this->table[i] != nullptr) {

            cout << *this->table[i];
        }
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Protected Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int HashTable::CreateHash(const int key) const { // DONE

    const int firstHashVal = CalcHash(key);

    return (this->table[firstHashVal] == nullptr) ? firstHashVal : DoubleHash(key);
}

int HashTable::CalcHash(const int key) const {

    return key % kTableSize;
}

int HashTable::CalcDoubleHash(const int insertion_key) const { // DONE

    return kTableSize - (insertion_key % kTableSize);
}

int HashTable::DoubleHash(const int insertion_key) const { // FINE

    // IDEA: Implement a counter to protected against infinite loops

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
void HashTable::Clear() { // DONE

    for (int i = 0; i < kTableSize; i++) {

        if (this->table[i] == nullptr) {

            continue;
        } else {

            delete this->table[i];
            this->table[i] = nullptr;
        }
    }
}


