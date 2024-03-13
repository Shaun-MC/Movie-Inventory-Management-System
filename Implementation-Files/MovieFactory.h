#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Movie.h"
#include "Movie_Comedy.h"
#include "Movie_Drama.h"
#include "Movie_Classic.h"

using namespace std;

class MovieFactory {
 public: 
  // Action
  static Movie* CreateMovie(string& movie_line);

 private:
  // Private function
  static Movie* CreateComedy(stringstream& movie_line);
  static Movie* CreateDrama(stringstream& movie_line);
  static Movie* CreateClassic(stringstream& movie_line);
};

#endif