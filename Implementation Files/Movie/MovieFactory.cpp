#include "MovieFactory.h"

// Actions
Movie* MovieFactory::createMovie(string& movie_line) { // UNTESTED

    sanatizeString(movie_line);

    stringstream str(movie_line);
    char movie_type;

    str >> movie_type;

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
        cout << "MovieFactory::createMovie() | Unsupported Movie Type: " << movie_type << endl; 
        return nullptr;
    }
}

// Private Member Functions
Movie* MovieFactory::createComedy(stringstream& movie_line) { // UNTESTED

    Movie* new_movie = new Comedy();

    if (!new_movie->setData(movie_line)) {

        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}

Movie* MovieFactory::createDrama(stringstream& movie_line) { // UNTESTED

    Movie* new_movie = new Drama();

    if (!new_movie->setData(movie_line)) {

        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}

Movie* MovieFactory::createClassic(stringstream& movie_line) { // UNTESTED

    Movie* new_movie = new Classic();

    if (!new_movie->setData(movie_line)) {

        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
} 

// Removes all the commas from the string
void MovieFactory::sanatizeString(string& movie_line) { // UNTESTED

    int curr_length = movie_line.length();

    for (int i = 0; i < curr_length; i++) {

        if (movie_line[i] == ',') {

            movie_line.erase(i--, 1);
            
            curr_length = movie_line.length();
        }
    }
}