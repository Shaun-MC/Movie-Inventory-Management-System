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

// Actions
bool MediaCollection::insert(Media*& media) { // DONE

    // Assumed all movies are DVD
    char insert_type = dynamic_cast<const Movie*>(media)->getMovieType();

    switch (insert_type) {

        case ('C'):
        return stock.at(insert_type).insert(*media);
        break;

        case ('D'):
        return stock.at(insert_type).insert(*media);
        break;

        case ('F'): 
        return stock.at(insert_type).insert(*media);
        break;

        default:
        return false;
    }
}

bool MediaCollection::retrieve(Media*& target, Media*& ret) { // UNTESTED

    Media* cpy_target = const_cast<Media*>(target);
    
    char retrieve_type = dynamic_cast<Movie*>(cpy_target)->getMovieType();

    switch (retrieve_type) {

        case 'F':
        return stock.at(retrieve_type).retrieve(*target, ret);
        break;

        case 'D':
        return stock.at(retrieve_type).retrieve(*target, ret);
        break;

        case 'C':
        return stock.at(retrieve_type).retrieve(*target, ret);
        break;

        default:
        
        cout << "MediaCollection::retrieve() | Unsupported Movie Type " << retrieve_type << endl;
        ret = nullptr;
        
        return false;
    }
}

void MediaCollection::display() const { // FINE

    for (auto pair : this->stock) {

        cout << pair.first << endl;
        pair.second.displayTree();
    }
}

// Unsure of nessecity
void MediaCollection::clear() { // UNSURE

    return;
}

