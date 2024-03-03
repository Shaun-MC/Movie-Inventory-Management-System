#include "Movie.h"

Movie::Movie() : director(""), title(""), movieType(0) {};

Movie::~Movie(){}

char Movie::getMediaType() const {

    return MediaType::dvd;
}

char Movie::getMovieType() const {

    return this->movieType;
}

string Movie::getTitle() const{
    
    return title;
}

string Movie::getDirector() const{
    
    return director;
}

int Movie::getYear() const {

    return this->release_year;
}

// Assumes stream is pointing to the stock value
bool Movie::setData(stringstream& movie_line) { // UNTESTED

    // Execution Order Does Not Matter - If 1 fails, they all fail
    // RESEARCH BETTER WAY TO DO THIS
    return (!this->getSetStock(movie_line) || !this->getSetDirector(movie_line) || 
            !this->getSetTitle(movie_line)) ? false : true;
}

void Movie::setTitle(const string title){
    
    this->title = title;
}

void Movie::setDirector(const string name){
    
    this->director = name;
}

void Movie::setYear(const int year) {

    this->release_year = year;
}

//display needs to check 
ostream &operator<<(ostream &ostrm, const Movie &movie){ 
    
    movie.display(ostrm);

    return ostrm;
}

bool Movie::getSetStock(stringstream& movie_line) { // DONE

    int stock = 0;

    movie_line >> stock;

    if (stock <= 0) {

        // Error Condition - Invalid Stock amount
        return false;
    }

    movie_line.ignore(); // Comma
    movie_line.ignore(); // Space

    this->setStock(stock);

    return true;
}

bool Movie::getSetDirector(stringstream& movie_line) { // DONE 

    string name = "";

    getline(movie_line, name, ',');

    movie_line.ignore(); // Space

    this->setDirector(name);

    return true;
}

bool Movie::getSetTitle(stringstream& movie_line) { // DONE

    string title = "";

    getline(movie_line, title, ',');
    
    movie_line.ignore(); // Space

    this->setTitle(title);

    return true;
}

bool Movie::getSetYear(stringstream& movie_line) { // DONE

    int year = 0;

    movie_line >> year;

    if (year <= 0) {

        // Error Condition - Improper year 
        return false;
    } 

    movie_line.ignore(); // New line character

    this->setYear(year);

    return true;
}

string Movie::reconstructLine() const { // DONE

    string line = to_string(this->getStock()) + ", " + this->getDirector() + 
                  ", " + this->getTitle() + ", "; 

    return line;
}
