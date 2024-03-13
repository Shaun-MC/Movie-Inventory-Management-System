#include "Drama.h"

// Constructor 
Drama::Drama() { 
    this->movieType = MovieType::drama;
    this->stock = 0;
    this->title = this->director = "";
}

// Destructor
Drama::~Drama() {}

// Set data for a Drama object from a stringstream
bool Drama::setData(stringstream& movie_line) { 
    return (!Movie::setData(movie_line) || !this->GetSetYear(movie_line)) ? false : true;
}

// Print header for displaying Drama objects
void Drama::PrintHeader() const {
    cout << "Dramas: " << endl << endl;
    cout << left << setw(8) << "Genre" << setw(8) << "Media" << setw(37) << "Title" << setw(25) <<
         "Director" << setw(8) << "Year" << "Stock" << endl;
}

// Overloaded operator to output Drama object to ostream
ostream& operator << (ostream& ostrm, const Drama& drama) {
    drama.Display(ostrm);
    return ostrm;
}

// Overloaded less than operator for comparing Drama objects
bool Drama::operator < (const Media& rval) const { 
    const Drama rval_temp = dynamic_cast<const Drama& >(rval);

    if (this->getDirector() != rval_temp.getDirector()) {
        return (this->getDirector() < rval_temp.getDirector());

    } else {
        return (this->getTitle() < rval_temp.getTitle());
    }
}

// Overloaded greater than operator for comparing Drama objects
bool Drama::operator > (const Media& rval) const {
    return (*this < rval || *this == rval) ? false : true;
}

// Overloaded equality operator for comparing Drama objects
bool Drama::operator == (const Media& rval) const { 
    const Drama rval_temp = dynamic_cast<const Drama& >(rval);

    return (this->getDirector() == rval_temp.getDirector() && 
            this->getTitle() == rval_temp.getTitle());
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Display information about the Drama object
void Drama::Display(ostream& ostrm) const {
    ostrm << setw(8) << this->getMovieType() << setw(8) << this->getMediaType() << setw(37) << this->getTitle() 
          << setw(25) << this->getDirector() << setw(8) << this->getYear() << this->getStock() << endl;
}
