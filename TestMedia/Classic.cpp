#include "Classic.h"

// Constructor - Destructor
Classic::Classic() : major_actor(""), release_date("") {

    this->movieType = MovieType::classic;

    this->stock = 0;

    this->title = this->director = "";
}

Classic::~Classic() {}

// Getters - Setters
string Classic::getMajorActor() const {

    return this->major_actor;
}

string Classic::getReleaseDate() const {

    return this->release_date;
}

// Assumes stream is pointing to the stock value
bool Classic::setData(stringstream& movie_line) { // UNTESTED

    // Execution Order doesn't matter, if 1 of them fails, they all fail
    // RESEARCH BETTER WAY TO DO THIS
    return (!Movie::setData(movie_line) || !this->getSetMA(movie_line) || !this->getSetDate(movie_line)) ? false : true;
}

void Classic::setMajorActor(const string f_name, const string l_name) {

    this->major_actor = f_name + " " + l_name;
}

void Classic::setReleaseDate(const string date)  {

    this->release_date = date;
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

bool Classic::operator > (const Media& rval) const {

    return !(*this < rval);
}

bool Classic::operator == (const Media& rval) const { // UNTESTED

    return (this->getReleaseDate() == dynamic_cast<const Classic& >(rval).getReleaseDate() && 
            this->getMajorActor() == dynamic_cast<const Classic& >(rval).getMajorActor());
}

// Private Member Functions

bool Classic::getSetMA(stringstream& movie_line) { // UNTESTED

    string f_name = "", l_name = ""; 

    movie_line >> f_name >> l_name;
    
    movie_line.ignore(); // Space

    this->setMajorActor(f_name, l_name);

    return true;
}

bool Classic::getSetDate(stringstream& movie_line) { // UNTESTED

    int month = 0, year = 0; 
    string date = "";

    movie_line >> month >> year;

    if (month <= 0 || year <= 0) {

        // Error Condition - Invalid Month / Year
        return false;
    }
    movie_line.ignore(); // End of Line character

    date = to_string(month) + " " + to_string(year);

    this->setReleaseDate(date);

    return true;
}

void Classic::display(ostream& ostrm) const {

    return;
}