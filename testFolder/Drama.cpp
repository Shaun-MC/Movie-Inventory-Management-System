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

// Operator Overloads
ostream& operator << (ostream& ostrm, const Drama& drama) {

    drama.display(ostrm);

    return ostrm;
}

bool Drama::operator < (const Media& rval) const { // DONE

    const Drama rval_temp = dynamic_cast<const Drama& >(rval);

    if (this->getDirector() != rval_temp.getDirector() && this->getDirector() < rval_temp.getDirector()) {

        return true;
    }

    return (this->getTitle() < rval_temp.getTitle());
}

bool Drama::operator > (const Media& rval) const {

    return !(*this < rval);
}

bool Drama::operator == (const Media& rval) const { // DONE

    const Drama rval_temp = dynamic_cast<const Drama& >(rval);

    return (this->getDirector() == rval_temp.getDirector() && 
            this->getTitle() == rval_temp.getTitle());
}

// Private Member Functions
string Drama::reconstructLine() const { // DONE

    string line = Movie::reconstructLine();

    line += to_string(this->getYear());

    return line;
}

void Drama::display(ostream& ostrm) const {

    ostrm << this->reconstructLine();
}
