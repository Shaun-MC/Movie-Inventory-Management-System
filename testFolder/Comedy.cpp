#include "Comedy.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Comedy::Comedy() { // DONE

    this->movieType = MovieType::comedy;

    this->stock = 0;

    this->title = this->director = "";
}

Comedy::~Comedy() {}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Setter
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool Comedy::setData(stringstream& movie_line) { // DONE

    return (!Movie::setData(movie_line) || !Movie::GetSetYear(movie_line)) ? false : true;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Comedy::PrintHeader() const {

    cout << "Comedies: " << endl << endl;

    cout << left << setw(8) << "Genre" << setw(8) << "Media" << setw(37) << "Title" << setw(25) <<
         "Director" << setw(8) << "Year" << "Stock" << endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Operator Overloads
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ostream& operator << (ostream& ostrm, const Comedy& comedy) { // DONE

    comedy.Display(ostrm);

    return ostrm;
}

bool Comedy::operator < (const Media& rval) const { // DONE

    // Sorting Criteria: Title & Year
    const Comedy rval_temp = static_cast<const Comedy& >(rval);

    // Could condence into a single return statement, less readable
    if (this->getTitle() != rval_temp.getTitle()) {

        return (this->getTitle() < rval_temp.getTitle());
    } else {

        return (this->getYear() < rval_temp.getYear());
    }
}

bool Comedy::operator > (const Media& rval) const {

    return (*this < rval || *this == rval) ? false : true;
}

bool Comedy::operator == (const Media& rval) const { // DONE

    // Sorting Criteria: Title & Year
    const Comedy rval_temp = static_cast<const Comedy& >(rval);

    return (this->getTitle() == rval_temp.getTitle() && 
            this->getYear() == rval_temp.getYear());
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Memeber Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Comedy::Display(ostream& ostrm) const {

    ostrm << setw(8) << this->getMovieType() << setw(8) << this->getMediaType() << setw(37) << this->getTitle() 
          << setw(25) << this->getDirector() << setw(8) << this->getYear() << this->getStock() << endl;
}

