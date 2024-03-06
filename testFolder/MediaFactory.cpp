#include "MediaFactory.h"

Media* MediaFactory::createDVDMovie(string& movie_line) { // DONE

    return MovieFactory::CreateMovie(movie_line);
}