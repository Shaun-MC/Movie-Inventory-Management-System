#include "Classic.h"

// Constructor - Destructor
Classic::Classic() : release_month(0) { // DONE

    this->movieType = MovieType::classic;

    this->stock = 0;

    this->title = this->director = "";
}

Classic::~Classic() {}

// Getters - Setters
// Returns the first major actor in the map
string Classic::getMajorActor() const { // DONE

    return this->major_actors.begin()->first;
}

int Classic::getReleaseMonth() const { // DONE

    return this->release_month;
}

// Assumes stream is pointing to the stock value
bool Classic::setData(stringstream& movie_line) { // DONE

    // Execution Order doesn't matter, if 1 of them fails, they all fail
    // RESEARCH BETTER WAY TO DO THIS
    return (!Movie::setData(movie_line) || !this->getSetMA(movie_line) || 
            !this->getSetMonth(movie_line) || !Movie::getSetYear(movie_line)) ? false : true;
}

void Classic::InsertMajorActor(const string name, const int stock_amount) {

    this->major_actors.insert({name, stock_amount});
}

void Classic::setReleaseMonth(const int date)  {

    this->release_month = date;
}

// Actions
void Classic::InsertMajorActor(const string name, const int stock_amount) {

    this->major_actors.insert({name, stock_amount});
}

// Operator Overloads
ostream& operator << (ostream& ostrm, const Classic& classic) {

    classic.display(ostrm);

    return ostrm;
}

bool Classic::operator < (const Media& rval) const { // DONE

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

    return (*this < rval || *this == rval) ? false : true;
}

bool Classic::operator == (const Media& rval) const { // DONE

    const Classic rval_temp = dynamic_cast<const Classic& >(rval);

    // Able to combine movie stocks if we know they're the same movie, the date is irrelevant here
    return (this->getDirector() == rval_temp.getDirector() && this->getTitle() == rval_temp.getTitle());
    
    /*return (this->getYear() == rval_temp.getYear() && 
            this->getReleaseMonth() == rval_temp.getReleaseMonth();*/
}

// Private Member Functions

bool Classic::getSetMA(stringstream& movie_line) { // UNTESTED

    string name = "";

    getline(movie_line, name, ' ');

    this->InsertMajorActor(name, this->stock);

    return true;
}

bool Classic::getSetMonth(stringstream& movie_line) { // DONE

    int month = 0;

    movie_line >> month;

    if (month <= 0) {

        // Error Condition - Invalid Month
        return false;
    }
    movie_line.ignore(); // Space

    this->setReleaseMonth(month);

    return true;
}

void Classic::display(ostream& ostrm) const { // UNTESTED

    // Displays all non actor information
    ostrm << setw(8) << this->getMovieType() << setw(8) << this->getMediaType() << setw(37) << this->getTitle() 
          << setw(25) << this->getDirector() << setw(8) << this->getYear() << this->getStock() << endl;
    
    // Display the Actor Name and the stock of movie associated w/ that actor 
    for (auto pair : this->major_actors) {

        ostrm << setw(40) << pair.first << setw(20) << setfill('-') << setfill(' ') << pair.second << endl;
    }
}