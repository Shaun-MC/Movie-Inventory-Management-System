#include "Drama.h"

// Constructor - Destructor
Drama::Drama() {

    this->movieType = MovieType::drama;

    this->stock = this->release_year = 0;

    this->title = this->director = "";
}

Drama::~Drama() {}

// Getter
bool Drama::setData(stringstream& movie_line) {

    return (!Movie::setData(movie_line) || !Movie::getSetYear(movie_line)) ? false : true;
}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Drama& drama) {

    drama.display(ostrm);

    return ostrm;
}

bool Drama::operator < (const Media& rval) const { // UNTESTED

    return (this->getDirector() < dynamic_cast<const Drama& >(rval).getDirector() && 
            this->getTitle() < dynamic_cast<const Drama& >(rval).getTitle());
}

bool Drama::operator > (const Media& rval) const {

    return !(*this < rval);
}

bool Drama::operator == (const Media& rval) const { // UNTESTED

    return (this->getDirector() == dynamic_cast<const Drama& >(rval).getDirector() && 
            this->getTitle() == dynamic_cast<const Drama& >(rval).getTitle());
}

// Private Member Function
void Drama::display(ostream& ostrm) const {

    return;
}
