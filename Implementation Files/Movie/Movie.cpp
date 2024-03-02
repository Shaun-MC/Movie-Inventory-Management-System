#include "Movie.h"

Movie::Movie() : director(""), title(""), release_year(0), movieType(0) {};

Movie::~Movie(){}

string Movie::getTitle() const{
    
    return title;
}

int Movie::getYear() const{
    
    return release_year;
}

string Movie::getDirector() const{
    
    return director;
}

char Movie::getMediaType() const {

    return MediaType::dvd;
}

char Movie::getMovieType() const {

    return this->movieType;
}

// Assumes stream is pointing to the stock value
bool Movie::setData(stringstream& movie_line) { // UNTESTED

    // Execution Order Does Not Matter - If 1 fails, they all fail
    // RESEARCH BETTER WAY TO DO THIS
    if (!this->getSetStock(movie_line) || this->getSetDirector(movie_line) || 
        !this->getSetTitle(movie_line) || this->getSetYear(movie_line)) {

        return false;
    }

    return true;
}

void Movie::setTitle(string title){
    
    this->title = title;
}

int Movie::setYear(int year){
    
    this->release_year = year;
}

void Movie::setDirector(string f_name, string l_name){
    
    this->director = f_name + " " + l_name;
}

char Movie::getMovieType() const{
    
    return this->movieType;
}

//display needs to check 
ostream &operator<<(ostream &ostrm, const Movie &movie){ 
    
    movie.display(ostrm);

    return ostrm;
}

bool Movie::getSetStock(stringstream& movie_line) {

    int stock = 0;

    if (!(movie_line >> stock) || stock <= 0) {

        // Error Condition - Invalid Stock amount
        return false;
    }
    movie_line.ignore();

    this->setStock(stock);

    return true;
}

bool Movie::getSetDirector(stringstream& movie_line) {

    string fname = "", lname = "";

    if (!(movie_line >> fname >> lname)) {

        // Error Condition - Something wrong w/ director name - not likely
        return false; 
    }
    movie_line.ignore();

    this->setDirector(fname, lname);

    return true;
}

bool Movie::getSetTitle(stringstream& movie_line) {

    string title = "";
    
    if (!(movie_line >> title)) {

        // Error Condition - No Movie Title
        return false;
    }
    movie_line.ignore();

    this->setTitle(title);
}

bool Movie::getSetYear(stringstream& movie_line) {

    int year = 0;

    // Execution Order DOES MATTER
    if (!(movie_line >> year) || year <= 0) {

        // Error Condition - Improper year 
        return false;
    }
    movie_line.ignore();

    this->setYear(year);
}
