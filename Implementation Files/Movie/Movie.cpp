#include "Movie.h"

Movie::Movie(){
    director = " ";
    title = " ";
    release_year = 0;
    movieType = ' ';
}

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

void Movie::setTitle(string title){
    this->title = title;
}

int Movie::setYear(int year){
    this->release_year = year;
}

void Movie::setDirector(string title){
    this->director = title;
}

char Movie::getMovieType() const{
    return movieType;
}

//display needs to check 
ostream &operator<<(ostream &ostrm, const Movie &obj){ 
    obj.display(ostrm);
    return ostrm;
}
