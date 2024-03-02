#include "MediaFactory.h"

Media*& MediaFactory::createDVDMovie(ifstream& movie_list) {

    return MovieFactory::createMovie(movie_list);
}