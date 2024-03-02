#include "Comedy.h"

// Constructor - Destructor
Comedy::Comedy() : release_year(0) {

    this->movieType = MovieType::drama;

    this->stock = 0;

    this->title = this->director = "";
}

Comedy::~Comedy() {}

// Getter - Setter

bool Comedy::setData(stringstream& movie_line) {

    return (!Movie::setData(movie_line) || !Movie::getSetYear(movie_line)) ? false : true;
}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Comedy& comedy) { // UNTESTED

    comedy.display(ostrm);

    return ostrm;
}

bool Comedy::operator < (const Media& rval) const { // UNTESTED

    // Sorting Criteria: Title & Year
    const Comedy rval_temp = dynamic_cast<const Comedy& >(rval);

    // Could condence into a single return statement, less readable
    if (this->getTitle() != rval_temp.getTitle() && this->getTitle() < rval_temp.getTitle()) {

        return true;
    }

    return (this->getYear() < rval_temp.getYear());
}

bool Comedy::operator > (const Media& rval) const {

    return !(*this < rval);
}

bool Comedy::operator == (const Media& rval) const { // UNTESTED

    // Sorting Criteria: Title & Year
    const Comedy rval_temp = dynamic_cast<const Comedy& >(rval);

    return (this->getTitle() == rval_temp.getTitle() && 
            this->getYear() == rval_temp.getYear());
}

// Private Member Functions

void Comedy::display(ostream& ostrm) const {

    return;
}
