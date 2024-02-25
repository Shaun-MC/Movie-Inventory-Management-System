#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"

class Drama : public Movie {

 public: 

  // Constructor - Destructor
  Comedy();
  ~Comedy();

  // Getters - Setters
  virtual MovieType getMovieType() const;

  // Actions

  // Operator Overloads
};

#endif 