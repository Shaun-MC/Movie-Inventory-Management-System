#include "Movie.h"

Movie::Movie(){
    director_ = " ";
    title = " ";
    release_year_ = 0;
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
    this->title_ = title;
}

int Movie::setYear(int year){
    this->release_year_ = year;
}

void Movie::setDirector(string title){
    this->director_ = title;
}

MovieType Movie::getMovieType() const{
    return movieType;
}

//display needs to check 
ostream &operator<<(ostream &ostrm, const Movie &obj){ 
    obj.display(ostrm);
    return ostrm;
}
