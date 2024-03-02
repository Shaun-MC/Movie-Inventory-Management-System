#include "Media.h"

// Constructor 
Media::Media() : stock(0) {};

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

void Media::reduceStock(const int amount) {

    this->stock -= amount;
}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Media& media) {

    return media.display(ostrm); 
}
