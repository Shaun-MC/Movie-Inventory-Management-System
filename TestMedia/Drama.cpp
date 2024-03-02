#include "Drama.h"

// Constructor - Destructor
Drama::Drama() : release_year(0) {

    this->movieType = MovieType::drama;

    this->stock = 0;

    this->title = this->director = "";
}

Drama::~Drama() {}

// Getter - Setters
int Drama::getYear() const{
    
    return release_year;
}

bool Drama::setData(stringstream& movie_line) {

    return (!Movie::setData(movie_line) || !this->getSetYear(movie_line)) ? false : true;
}

void Drama::setYear(const int year){
    
    this->release_year = year;
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

bool Drama::getSetYear(stringstream& movie_line) {

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
