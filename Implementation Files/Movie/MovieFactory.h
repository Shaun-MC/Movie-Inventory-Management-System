#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_

#include <fstream>

#include "Movie.h"

class MovieFactory {

 public: 
  
  static Movie*& createMovie(const string& movie_line);

 private:

  Movie* createComedy(const string& movie_line);

  Movie* createDrama(const string& movie_line);

  Movie* createClassic(const string& movie_line);
};

#endif