#include "Media.h"

// Constructor 
Media::Media() : stock(0), type(MediaType::dvd) {};

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

void Media::incrementStock() {

    ++this->stock;
}

bool Media::decrementStock() { // DONE

    if (this->stock - 1 < 0) {

        // Error Conditon: Unable to reduce Stock
        return false;
    }

    --this->stock;
    return true;
}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Media& media) {

    media.display(ostrm);

    return ostrm;
}
