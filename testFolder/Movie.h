#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <sstream>

#include "Media.h"

class Movie : public Media {

 public: 

  // Constructor - Destructor
  Movie();
  virtual ~Movie();

  // Getter - Setters
  virtual char getMediaType() const;
  char getMovieType() const; 
  
  string getTitle() const;
  string getDirector() const;
  int getYear() const;
  
  virtual bool setData(stringstream& movie_line);
  void setMovieType(const char type);

  void setTitle(const string title);
  void setDirector(const string name);
  void setYear(const int year);

  // Actions
  virtual void PrintHeader() const = 0;

  // Operator Overloading
  friend ostream& operator << (ostream& ostrm, const Movie& obj);

  virtual bool operator < (const Media& rval) const = 0;
  virtual bool operator > (const Media& rval) const = 0;
  virtual bool operator == (const Media& rval) const = 0;
 
 protected: 
  
  char movieType; 
  
  string director;
  
  string title;

  int release_year;

  bool getSetStock(stringstream& movie_line);
  bool getSetDirector(stringstream& movie_line);
  bool getSetTitle(stringstream& movie_line);
  bool getSetYear(stringstream& movie_line);

  virtual void display(ostream& ostrm) const = 0;
};

#endif