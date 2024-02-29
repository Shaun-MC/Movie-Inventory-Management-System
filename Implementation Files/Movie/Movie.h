#ifndef MOVIE_H
#define MOVIE_H

#include "../Stock/Media.h"

class Movie : public Media {

 public: 

  // Constructor - Destructor
  Movie();
  virtual ~Movie();

  // Getter - Setters
  string getTitle() const;
  int getYear() const;
  string getDirector() const;
  
  void setTitle(string title);
  int setYear(int year);
  void setDirector(string title);

  virtual string getMediaType() const = 0; //abstract function (pure function)
  virtual char getMovieType() const; 
  
  // Actions
  virtual void display() const = 0; //abstract function (pure function)

  // Operator Overloading
  friend ostream& operator << (ostream& ostrm, const Movie& obj);
 
 protected: 
  
  MovieType movieType;
  
  string director;
  string title;
  int release_year;

};

#endif