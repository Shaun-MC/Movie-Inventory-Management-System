#include "MediaCollection.h"

// Constructor - Destructor
MediaCollection::MediaCollection() { // UNTESTED

    this->stock.insert( pair<char, AVLTree<Media> >(MovieType::comedy, comedies) );

    this->stock.insert( pair<char, AVLTree<Media> >(MovieType::drama, dramas) );

    this->stock.insert( pair<char, AVLTree<Media> >(MovieType::classic, classics) );
}

// Unsure of necessity 
MediaCollection::~MediaCollection() {

    this->clear();
}

// Getter
MediaCollection* MediaCollection::getCollection() { // UNTESTED

    if (instancePtr == nullptr) {

        instancePtr = new MediaCollection();
    } 

    return instancePtr;
}

// Actions
bool MediaCollection::insert(Media*& media) { // UNTESTED

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

bool MediaCollection::retrieve(const Media*& target, Media*& ret) { // UNTESTED

    Media* cpy_target = const_cast<Media*>(target);
    
    char retrieve_type = dynamic_cast<Movie*>(cpy_target)->getMovieType();

    switch (retrieve_type) {

        case 'F':
        return stock.at(retrieve_type).retrieve(target, ret);
        break;

        case 'D':
        return stock.at(retrieve_type).retrieve(target, ret);
        break;

        case 'C':
        return stock.at(retrieve_type).retrieve(target, ret);
        break;

        default:
        
        cout << "MediaCollection::retrieve() | Unsupported Movie Type " << retrieve_type << endl;
        ret = nullptr;
        
        return false;
    }
}

// Unsure of nessecity
void MediaCollection::clear() {

    return;
}