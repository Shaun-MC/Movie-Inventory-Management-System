#include "MovieFactory.h"

// Function to create a Movie object based on the provided movie line
Movie* MovieFactory::CreateMovie(string& movie_line) { 
    stringstream str(movie_line);
    char movie_type = 0;

    str >> movie_type;

    str.ignore();
    str.ignore(); 

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
            return nullptr;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Function to create a Comedy movie object from the provided stringstream
Movie* MovieFactory::CreateComedy(stringstream& movie_line) { 
    Movie* new_movie = new Comedy();

   if (!new_movie->setData(movie_line)) {
        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}

// Function to create a Drama movie object from the provided stringstream
Movie* MovieFactory::CreateDrama(stringstream& movie_line) { 
    Movie* new_movie = new Drama();

    if (!new_movie->setData(movie_line)) {
        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}

// Function to create a Classic movie object from the provided stringstream
Movie* MovieFactory::CreateClassic(stringstream& movie_line) { 
    Movie* new_movie = new Classic();

    if (!new_movie->setData(movie_line)) {
        delete new_movie;
        new_movie = nullptr;
    }

    return new_movie;
}