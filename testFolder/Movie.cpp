#include "Movie.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Movie::Movie() : director(""), title(""), movieType(0) {};

Movie::~Movie(){}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Getters - Setters
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
bool Movie::setData(stringstream& movie_line) { // DONE

    // Execution Order Does Not Matter - If 1 fails, they all fail
    // RESEARCH BETTER WAY TO DO THIS
    return (!this->GetSetStock(movie_line) || !this->GetSetDirector(movie_line) || 
            !this->GetSetTitle(movie_line)) ? false : true;
}

void Movie::setMovieType(const char type) {

    this->movieType = type;
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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Operator Overloads
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ostream& operator<<(ostream &ostrm, const Movie &movie){ 
    
    movie.Display(ostrm);

    return ostrm;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Movie::GetSetStock(stringstream& movie_line) { // DONE

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

bool Movie::GetSetDirector(stringstream& movie_line) { // DONE 

    string name = "";

    getline(movie_line, name, ',');

    movie_line.ignore(); // Space

    this->setDirector(name);

    return true;
}

bool Movie::GetSetTitle(stringstream& movie_line) { // DONE

    string title = "";

    getline(movie_line, title, ',');
    
    movie_line.ignore(); // Space

    this->setTitle(title);

    return true;
}

bool Movie::GetSetYear(stringstream& movie_line) { // DONE

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
