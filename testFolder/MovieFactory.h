#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

using namespace std;

class MovieFactory {

 public: 
  
  static Movie* CreateMovie(string& movie_line);

 private:

  static Movie* CreateComedy(stringstream& movie_line);

  static Movie* CreateDrama(stringstream& movie_line);

  static Movie* CreateClassic(stringstream& movie_line);
};

#endif