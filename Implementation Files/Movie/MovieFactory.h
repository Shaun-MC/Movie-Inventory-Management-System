#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Movie.h"

using namespace std;

class MovieFactory {

 public: 
  
  static Movie* createMovie(string& movie_line);

 private:

  static Movie* createComedy(stringstream& movie_line);

  static Movie* createDrama(stringstream& movie_line);

  static Movie* createClassic(stringstream& movie_line);

  static void sanatizeString(string& movie_line);
};

#endif