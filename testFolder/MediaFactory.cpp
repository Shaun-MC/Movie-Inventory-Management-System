#include "MediaFactory.h"

// Creates a DVD movie object based on the provided movie line
Media* MediaFactory::CreateDVDMovie(string& movie_line) { // DONE

    return MovieFactory::CreateMovie(movie_line);
}