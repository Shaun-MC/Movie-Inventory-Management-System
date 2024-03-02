#include "Comedy.h"

// Constructor - Destructor
Comedy::Comedy() : release_year(0) {

    this->movieType = MovieType::drama;

    this->stock = 0;

    this->title = this->director = "";
}

Comedy::~Comedy() {}

// Getter - Setter
int Comedy::getYear() const{
    
    return this->release_year;
}

bool Comedy::setData(stringstream& movie_line) {

    return (!Movie::setData(movie_line) || !this->getSetYear(movie_line)) ? false : true;
}

void Comedy::setYear(const int year){
    
    this->release_year = year;
}

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

bool Comedy::operator > (const Media& rval) const {

    return !(*this < rval);
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

bool Comedy::getSetYear(stringstream& movie_line) {

    int year = 0;

    movie_line >> year;

    if (year <= 0) {

        // Error Condition - Improper year 
        return false;
    } 

    movie_line.ignore(); // New line character

    this->setYear(year);

    return true;
}
