#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_

#include <fstream>

#include "Movie.h"

class MovieFactory {

 public: 
  
  static Movie*& createMovie(ifstream& movie_list);

 private:

  Movie* createComedy(ifstream& movie_list);

  Movie* createDrama(ifstream& movie_list);

  Movie* createClassic(ifstream& movie_list);
};

#endif