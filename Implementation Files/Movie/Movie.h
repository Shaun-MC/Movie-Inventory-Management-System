#ifndef MOVIE_H
#define MOVIE_H

#include "stock.h"

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

  virtual StockType getStockType() const = 0;
  virtual MovieType getMovieType() const; 
  
  // Actions
  virtual void display() const = 0;

  // Operator Overloading
  friend ostream& operator << (ostream& ostrm, const Movie& obj);
 
 protected: 
  
  MovieType movieType;
  
  string director;
  string title;
  int release_year;

}