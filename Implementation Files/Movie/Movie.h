#ifndef MOVIE_H
#define MOVIE_H

#include <sstream>
#include "../Media/Media.h"

class Movie : public Media {

 public: 

  // Constructor - Destructor
  Movie();
  virtual ~Movie();

  // Getter - Setters
  string getTitle() const;
  int getYear() const;
  string getDirector() const;
  
  bool setData(stringstream& movie_line);

  void setTitle(string title);
  int setYear(int year);
  void setDirector(string title);

  virtual string getMediaType() const = 0; // abstract function (pure function)
  virtual char getMovieType() const; 
  
  // Actions
  virtual void display() const = 0; // abstract function (pure function)

  // Operator Overloading
  friend ostream& operator << (ostream& ostrm, const Movie& obj);
 
 protected: 
  
  char movieType; //changed it 
  
  string director;
  
  string title;
  
  int release_year;

  virtual ostream& display(ostream &ostrm) const = 0;
};

#endif