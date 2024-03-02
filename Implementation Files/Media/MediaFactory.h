#ifndef MEDIA_FACTORY_H
#define MEDIA_FACTORY_H

#include <fstream>

#include "Media.h"

class MediaFactory {

 public: 

  Media* createDVDMovie(ifstream& movie_list);

};

#endif