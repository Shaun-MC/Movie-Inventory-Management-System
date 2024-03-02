#include "Movie.h"

Movie::Movie() : director(""), title(""), movieType(0) {};

Movie::~Movie(){}

string Movie::getTitle() const{
    
    return title;
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
    return (!this->getSetStock(movie_line) || !this->getSetDirector(movie_line) || 
            !this->getSetTitle(movie_line)) ? false : true;
}

void Movie::setTitle(const string title){
    
    this->title = title;
}

void Movie::setDirector(const string name){
    
    this->director = name;
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

    movie_line.ignore(); // Comma
    movie_line.ignore(); // Space

    this->setDirector(name);

    return true;
}

// Bug: If the movie title is more than 1 word it only catches the first one
bool Movie::getSetTitle(stringstream& movie_line) {

    string title = "";

    getline(movie_line, title, ',');
    
    movie_line.ignore(); // Comma
    movie_line.ignore(); // Space

    this->setTitle(title);

    return true;
}
