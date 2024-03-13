#include "Comedy.h"

// Constructor
Comedy::Comedy() { 
    this->movieType = MovieType::comedy;
    this->stock = 0;
    this->title = this->director = "";
}
// Destructor
Comedy::~Comedy() {}

// Set data for the Comedy movie
bool Comedy::setData(stringstream& movie_line) { 
    return (!Movie::setData(movie_line) || !Movie::GetSetYear(movie_line)) ? false : true;
}

// Print header for comedies
void Comedy::PrintHeader() const {
    cout << "Comedies: " << endl << endl;
    cout << left << setw(8) << "Genre" << setw(8) << "Media" << setw(37) << "Title" << setw(25) <<
         "Director" << setw(8) << "Year" << "Stock" << endl;
}

// Overloaded output stream operator for Comedy movie
ostream& operator << (ostream& ostrm, const Comedy& comedy) { 
    comedy.Display(ostrm);
    return ostrm;
}

// Comparison operator for less than
bool Comedy::operator < (const Media& rval) const { 
    const Comedy rval_temp = dynamic_cast<const Comedy& >(rval);

    if (this->getTitle() != rval_temp.getTitle()) {
        return (this->getTitle() < rval_temp.getTitle());
    } else {
        return (this->getYear() < rval_temp.getYear());
    }
}

// Comparison operator for greater than
bool Comedy::operator > (const Media& rval) const {
    return (*this < rval || *this == rval) ? false : true;
}

// Comparison operator for equality
bool Comedy::operator == (const Media& rval) const {
    const Comedy rval_temp = dynamic_cast<const Comedy& >(rval);

    return (this->getTitle() == rval_temp.getTitle() && 
            this->getYear() == rval_temp.getYear());
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Memeber Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Display function to output comedy movie information
void Comedy::Display(ostream& ostrm) const {
    ostrm << setw(8) << this->getMovieType() << setw(8) << this->getMediaType() << setw(37) << this->getTitle() 
          << setw(25) << this->getDirector() << setw(8) << this->getYear() << this->getStock() << endl;
}

