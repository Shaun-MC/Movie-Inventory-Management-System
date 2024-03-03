#include "MovieFactory.h"

// Actions
Movie* MovieFactory::createMovie(string& movie_line) { // DONE

    stringstream str(movie_line);
    char movie_type;

    // Cannot support movie types being more than 1 character
    str >> movie_type;

    str.ignore(); // Comma
    str.ignore(); // Space

    switch (movie_type) {

        case 'F':
        return MovieFactory::createComedy(str);
        break;

        case 'D':
        return MovieFactory::createDrama(str);
        break;

        case 'C':
        return MovieFactory::createClassic(str);
        break;

        default: 
        cerr << "MovieFactory::createMovie() | Unsupported Movie Type: " << movie_type << endl; 
        return nullptr;
    }
}

// Private Member Functions
Movie* MovieFactory::createComedy(stringstream& movie_line) { // DONE

    Movie* new_movie = new Comedy();

   if (!new_movie->setData(movie_line)) {

        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}

Movie* MovieFactory::createDrama(stringstream& movie_line) { // DONE

    Movie* new_movie = new Drama();

    if (!new_movie->setData(movie_line)) {

        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}

Movie* MovieFactory::createClassic(stringstream& movie_line) { // DONE

    Movie* new_movie = new Classic();

    if (!new_movie->setData(movie_line)) {

        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}