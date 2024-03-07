#include "MovieFactory.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Movie* MovieFactory::CreateMovie(string& movie_line) { // DONE

    stringstream str(movie_line);
    char movie_type;

    // Cannot support movie types being more than 1 character
    str >> movie_type;

    str.ignore(); // Comma
    str.ignore(); // Space

    switch (movie_type) {

        case 'F':
        return CreateComedy(str);
        break;

        case 'D':
        return CreateDrama(str);
        break;

        case 'C':
        return CreateClassic(str);
        break;

        default: 
            cerr << "Error: " << movie_type << " Invaild Genre. Try Again." << endl;
            //cerr << "MovieFactory::createMovie() | Unsupported Movie Type: " << movie_type << endl; 
        return nullptr;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Movie* MovieFactory::CreateComedy(stringstream& movie_line) { // DONE

    Movie* new_movie = new Comedy();

   if (!new_movie->setData(movie_line)) {

        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}

Movie* MovieFactory::CreateDrama(stringstream& movie_line) { // DONE

    Movie* new_movie = new Drama();

    if (!new_movie->setData(movie_line)) {

        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}

Movie* MovieFactory::CreateClassic(stringstream& movie_line) { // DONE

    Movie* new_movie = new Classic();

    if (!new_movie->setData(movie_line)) {

        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}