#include "Media.h"

// Constructor 
Media::Media() : stock(0) {};

Media::~Media() {}

// Getter - Setter
int Media::getStock() const {

    return this->stock;
}

void Media::setStock(const int amount) {

    this->stock = amount;
}

// Actions
void Media::addStock(const int amount) {

    this->stock += amount;
}

bool Media::reduceStock(const int amount) {

    if (this->stock - amount < 0) {

        // Error Conditon: Unable to reduce Stock
        return false;
    }

    this->stock -= amount;
    return true;
}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Media& media) {

    media.display(ostrm);

    return ostrm;
}
