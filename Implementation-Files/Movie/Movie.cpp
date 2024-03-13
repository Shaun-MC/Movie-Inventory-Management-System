#include "Movie.h"

// Constructor 
Movie::Movie() : director(""), title(""), movieType(0) {};

// Destructor
Movie::~Movie(){}

// Getter for media type
char Movie::getMediaType() const {
    return MediaType::dvd;
}

// Getter for movie type
char Movie::getMovieType() const {
    return this->movieType;
}

// Getter for movie title
string Movie::getTitle() const{
    return title;
}

// Getter for movie director
string Movie::getDirector() const{
    return director;
}

// Getter for movie release year
int Movie::getYear() const {
    return this->release_year;
}

// setData function to parse and set movie data from stringstream
bool Movie::setData(stringstream& movie_line) { 
    return (!this->GetSetStock(movie_line) || 
            !this->GetSetDirector(movie_line) || 
            !this->GetSetTitle(movie_line)
            ) ? false : true;
}

// Setter for movie type
void Movie::setMovieType(const char type) {
    this->movieType = type;
}

// Setter for movie title
void Movie::setTitle(const string title){
    this->title = title;
}

// Setter for movie director
void Movie::setDirector(const string name){
    this->director = name;
}

// Setter for movie release year
void Movie::setYear(const int year) {
    this->release_year = year;
}

// Overloaded output stream operator for Movie
ostream& operator<<(ostream &ostrm, const Movie &movie){ 
    movie.Display(ostrm);
    return ostrm;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Function to extract and set movie stock from stringstream
bool Movie::GetSetStock(stringstream& movie_line) { 
    int stock = 0;
    movie_line >> stock;

    if (stock <= 0) {
        return false;
    }

    movie_line.ignore(); 
    movie_line.ignore(); 

    this->setStock(stock);
    return true;
}

// Function to extract and set movie director from stringstream
bool Movie::GetSetDirector(stringstream& movie_line) { 
    string name = "";

    getline(movie_line, name, ',');
    movie_line.ignore(); 
    this->setDirector(name);

    return true;
}

// Function to extract and set movie title from stringstrea
bool Movie::GetSetTitle(stringstream& movie_line) { 
    string title = "";

    getline(movie_line, title, ',');
    movie_line.ignore(); 
    this->setTitle(title);

    return true;
}

// Function to extract and set movie release year from stringstream
bool Movie::GetSetYear(stringstream& movie_line) { 
    int year = 0;

    movie_line >> year;

    if (year <= 0) {
        return false;
    } 

    movie_line.ignore(); 
    this->setYear(year);

    return true;
}
