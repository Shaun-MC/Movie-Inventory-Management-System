#ifndef MEDIA_FACTORY_H
#define MEDIA_FACTORY_H

#include <fstream>

#include "Media.h"
#include "../Movie/MovieFactory.h"

class MediaFactory {

 public: 

  static Media*& createDVDMovie(ifstream& movie_list);
};

#endif