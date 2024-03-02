#include "MediaFactory.h"

Media*& MediaFactory::createDVDMovie(const string& movie_line) {

    return MovieFactory::createMovie(movie_line);
}