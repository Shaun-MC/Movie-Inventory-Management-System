#include "Classic.h"

// Constructor - Destructor
Classic::Classic() : major_actor(""), release_month(0) {

    this->movieType = MovieType::classic;

    this->stock = this->release_year = 0;

    this->title = this->director = "";
}

Classic::~Classic() {}

// Getter - Setter
char Classic::getMovieType() const {

    return this->type;
}

string Classic::getMajorActor() const {

    return this->major_actor;
}

int Classic::getReleaseMonth() const {

    return this->release_month;
}

string Classic::getReleaseDate() const {

    return this->release_month + " " + this->release_year;
}

// Assumes stream is pointing to the stock value
bool Classic::setData(stringstream& movie_line) { // UNTESTED

    // Execution Order doesn't matter, if 1 of them fails, they all fail
    // RESEARCH BETTER WAY TO DO THIS
    return (!Movie::setData(movie_line) || !this->getSetMA(movie_line) || !this->getSetMonth(movie_line));
}

void Classic::setMajorActor(const string f_name, const string l_name) {

    this->major_actor = f_name + " " + l_name;
}

void Classic::setReleaseMonth(const int month)  {

    this->release_month = month;
}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Classic& classic) {

    classic.display(ostrm);

    return ostrm;
}

bool Classic::operator < (const Media& rval) const { // UNTESTED

    // Sorting Criteria: Release Date & Headline Actor
    return (this->getReleaseDate() < dynamic_cast<const Classic& >(rval).getReleaseDate() && 
            this->getMajorActor() < dynamic_cast<const Classic& >(rval).getMajorActor());
}

bool Classic::operator == (const Media& rval) const { // UNTESTED

    return (this->getReleaseDate() == dynamic_cast<const Classic& >(rval).getReleaseDate() && 
            this->getMajorActor() == dynamic_cast<const Classic& >(rval).getMajorActor());
}

// Private Member Functions

bool Classic::getSetMA(stringstream& movie_line) { // UNTESTED

    string f_name = "", l_name = "";
    
    if (!(movie_line >> f_name >> l_name)) {

        // Error Condition - Invalid Major Actor Data;
        return false;
    }
    movie_line.ignore();

    this->setMajorActor(f_name, l_name);

    return true;
}

bool Classic::getSetMonth(stringstream& movie_line) { // UNTESTED

    int month = 0;

    // Execution Order DOES MATTER
    if (!(movie_line >> month) || month <= 0) {

        // Error Condition - Invalid Month
        return false;
    }
    movie_line.ignore();

    return true;
}

void Classic::display(ostream& ostrm) const {

    return;
}