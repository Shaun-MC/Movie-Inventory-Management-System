#include "MediaCollection.h"

// Constructor - Destructor
MediaCollection::MediaCollection() {

    this->stock.insert( pair<char, AVLTree<Media> >(MovieType.Comedy, comedies) );

    this->stock.insert( pair<char, AVLTree<Media> >(MovieType.Drama, dramas) );

    this->stock.insert( pair<char, AVLTree<Media> >(MovieType.Classic, classics) );
}

MediaCollection::~MediaCollection() {

    // Unessecary??
}

// Getter
MediaCollection* MediaCollection::getCollection() {

    if (instancePtr == nullptr) {

        instancePtr = new MediaCollection();
    } 

    return instancePtr;
}

// Actions
bool MediaCollection::insert(const Media*& media) {

    // Assumed all movies are DVD - no checking for it
    char insert_type = dynamic_cast<Movie*>(media)->getMovieType();

    switch (insert_type) {

        case ('F'): 

        return stock.at(insert_type).insert(media);
        break;

        case ('D'):
        return stock.at(insert_type).insert(media);
        break;

        case ('C'):
        return stock.at(insert_type).insert(media);

        default:
        return false;
    }
}