#include "Media.h"

// Constructor 
Media::Media() : stock(0), type(MediaType::dvd) {};

// Destructor
Media::~Media() {}

// Get the current stock of the media
int Media::getStock() const {
    return this->stock;
}

// Set the stock of the media
void Media::setStock(const int amount) {
    this->stock = amount;
}

// Set the type of the media
void Media::setMediaType(const MediaType type) {
    this->type = type;
}

// Add stock to the media
void Media::AddStock(const int amount) {
    this->stock += amount;
}

// Increment the stock of the media by one
void Media::IncrementStock() {
    ++this->stock;
}

// Decrement the stock of the media by one
bool Media::DecrementStock() { 
    if (this->stock - 1 < 0) {
        return false;
    }

    --this->stock;
    return true;
}

// Output operator to display media information
ostream& operator << (ostream& ostrm, const Media& media) {
    media.Display(ostrm);
    return ostrm;
}