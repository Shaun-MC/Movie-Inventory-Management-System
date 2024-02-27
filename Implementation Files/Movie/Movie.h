#ifndef MOVIE_H
#define MOVIE_H

#include "stock.h"
#include<iostream>
using namespace std;

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

  virtual char getStockType() const = 0; //abstract function (pure function)
  virtual char getMovieType() const; 

  // Operator Overloading
  friend ostream& operator << (ostream& ostrm, const Movie& obj);
 
 protected: 
  
  char movieType; //changed it 
  string director;
  string title;
  int release_year;
  virtual void display(ostream &ostrm) const = 0;
};

#endif