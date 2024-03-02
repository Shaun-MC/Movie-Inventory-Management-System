#include "Comedy.h"

// Constructor - Destructor
Comedy::Comedy() {

    this->movieType = MovieType::comedy;

    this->stock = this->release_year = 0;

    this->title = this->director = "";
}

Comedy::~Comedy() {}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Comedy& comedy) { // UNTESTED

    comedy.display(ostrm);

    return ostrm;
}

bool Comedy::operator < (const Media& rval) const { // UNTESTED

    // Sorting Criteria: Title & Year
    return (this->getTitle() < dynamic_cast<const Comedy& >(rval).getTitle() && 
            this->getYear() < dynamic_cast<const Comedy& >(rval).getYear());
}

bool Comedy::operator == (const Media& rval) const { // UNTESTED

    // Sorting Criteria: Title & Year
    return (this->getTitle() == dynamic_cast<const Comedy& >(rval).getTitle() && 
            this->getYear() == dynamic_cast<const Comedy& >(rval).getYear());
}

// Private Member Functions

void Comedy::display(ostream& ostrm) const {

    return;
}
