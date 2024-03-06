#ifndef MEDIA_FACTORY_H
#define MEDIA_FACTORY_H

#include <fstream>

#include "Media.h"
#include "MovieFactory.h"

class MediaFactory {

 public: 

  static Media* CreateDVDMovie(string& movie_line);
};

#endif