#include "MediaFactory.h"

Media* MediaFactory::CreateDVDMovie(string& movie_line) { // DONE

    return MovieFactory::CreateMovie(movie_line);
}