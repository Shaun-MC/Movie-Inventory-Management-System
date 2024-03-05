#include "Drama.h"

// Constructor - Destructor
Drama::Drama() { // DONE

    this->movieType = MovieType::drama;

    this->stock = 0;

    this->title = this->director = "";
}

Drama::~Drama() {}

// Getter - Setters
bool Drama::setData(stringstream& movie_line) { // DONE

    return (!Movie::setData(movie_line) || !this->getSetYear(movie_line)) ? false : true;
}

// Actions
void Drama::PrintHeader() const {

    cout << "Dramas: " << endl << endl;

    cout << left << setw(8) << "Genre" << setw(8) << "Media" << setw(37) << "Title" << setw(25) <<
         "Director" << setw(8) << "Year" << "Stock" << endl;
}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Drama& drama) {

    drama.display(ostrm);

    return ostrm;
}

// Sorting Criteria: Director & Title
bool Drama::operator < (const Media& rval) const { // DONE

    const Drama rval_temp = dynamic_cast<const Drama& >(rval);

    if (this->getDirector() != rval_temp.getDirector()) {

        return (this->getDirector() < rval_temp.getDirector());
    } else {

        return (this->getTitle() < rval_temp.getTitle());
    }
}

bool Drama::operator > (const Media& rval) const {

    return (*this < rval || *this == rval) ? false : true;
}

bool Drama::operator == (const Media& rval) const { // DONE

    const Drama rval_temp = dynamic_cast<const Drama& >(rval);

    return (this->getDirector() == rval_temp.getDirector() && 
            this->getTitle() == rval_temp.getTitle());
}

void Drama::display(ostream& ostrm) const {

    ostrm << setw(8) << this->getMovieType() << setw(8) << this->getMediaType() << setw(37) << this->getTitle() 
          << setw(25) << this->getDirector() << setw(8) << this->getYear() << this->getStock() << endl;
}
