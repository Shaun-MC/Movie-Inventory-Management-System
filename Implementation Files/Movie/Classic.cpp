#include "Classic.h"

// Constructor - Destructor
Classic::Classic() : major_actor("") {

    this->movieType = MovieType::classic;

    this->stock = 0;

    this->title = this->director = "";
}

Classic::~Classic() {}

// Getters - Setters
string Classic::getMajorActor() const {

    return this->major_actor;
}

int Classic::getReleaseMonth() const {

    return this->release_month;
}

// Assumes stream is pointing to the stock value
bool Classic::setData(stringstream& movie_line) { // UNTESTED

    // Execution Order doesn't matter, if 1 of them fails, they all fail
    // RESEARCH BETTER WAY TO DO THIS
    return (!Movie::setData(movie_line) || !this->getSetMA(movie_line) || 
            !this->getSetMonth(movie_line) || !Movie::getSetYear(movie_line)) ? false : true;
}

void Classic::setMajorActor(const string f_name, const string l_name) {

    this->major_actor = f_name + " " + l_name;
}

void Classic::setReleaseMonth(const int date)  {

    this->release_month = date;
}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Classic& classic) {

    classic.display(ostrm);

    return ostrm;
}

bool Classic::operator < (const Media& rval) const { // UNTESTED

    // Sorting Criteria: Release Date & Headline Actor
    const Classic rval_temp = dynamic_cast<const Classic& >(rval);

    if (this->getYear() != rval_temp.getYear()) {

        return this->getYear() < rval_temp.getYear();
    }

    if (this->getReleaseMonth() != rval_temp.getReleaseMonth()) {

        return this->getReleaseMonth() < rval_temp.getReleaseMonth();  
    }

    return this->getMajorActor() < rval_temp.getMajorActor();
}

bool Classic::operator > (const Media& rval) const {

    return !(*this < rval);
}

bool Classic::operator == (const Media& rval) const { // UNTESTED

    const Classic rval_temp = dynamic_cast<const Classic& >(rval);

    return (this->getYear() == rval_temp.getYear() && 
            this->getReleaseMonth() == rval_temp.getReleaseMonth() && 
            this->getMajorActor() == rval_temp.getMajorActor());
}

// Private Member Functions

bool Classic::getSetMA(stringstream& movie_line) { // UNTESTED

    string f_name = "", l_name = ""; 

    movie_line >> f_name >> l_name;
    
    movie_line.ignore(); // Space

    this->setMajorActor(f_name, l_name);

    return true;
}

bool Classic::getSetMonth(stringstream& movie_line) { // UNTESTED

    int month = 0;

    movie_line >> month;

    if (month <= 0) {

        // Error Condition - Invalid Month / Year
        return false;
    }
    movie_line.ignore(); // Space

    this->setReleaseMonth(month);

    return true;
}

string Classic::reconstructLine() const {

    string line = Movie::reconstructLine();

    line += this->getMajorActor() + " " + to_string(this->getReleaseMonth()) + 
            to_string(this->getYear());

    return line;
}

void Classic::display(ostream& ostrm) const {

    ostrm << this->reconstructLine();
}