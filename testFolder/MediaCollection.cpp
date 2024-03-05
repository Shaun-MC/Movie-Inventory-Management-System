#include "MediaCollection.h"
#include <vector>

// Constructor - Destructor
MediaCollection::MediaCollection() : kComedyIndex(0), kDramaIndex(1), kClassicIndex(2)  { // DONE

    // Each insert also calls the AVLTree destructor for some reason - TEST
    this->stock.push_back(make_pair(MovieType::comedy, this->comedies));

    this->stock.push_back(make_pair(MovieType::drama, this->dramas));

    this->stock.push_back(make_pair(MovieType::classic, this->classics));
}

MediaCollection::~MediaCollection() {};

// Actions
bool MediaCollection::insert(Media*& media) { // DONE

    // Assumed all movies are DVD
    char insert_type = dynamic_cast<const Movie*>(media)->getMovieType();

    switch (insert_type) {

        case MovieType::comedy :
        return stock[kComedyIndex].second.insert(media);
        break;

        case MovieType::drama :
        return stock[kDramaIndex].second.insert(media);
        break;

        case MovieType::classic :
        return stock[kClassicIndex].second.insert(media); 
        break;

        default:
        return false;
    }
}

bool MediaCollection::retrieve(Media*& target, Media*& ret) { // UNTESTED

    Media* cpy_target = const_cast<Media*>(target);
    
    char retrieve_type = dynamic_cast<Movie*>(cpy_target)->getMovieType();

    switch (retrieve_type) {

        case MovieType::comedy :
        return stock[kComedyIndex].second.retrieve(*target, ret);
        break;

        case MovieType::drama :
        return stock[kDramaIndex].second.retrieve(*target, ret);
        break;

        case MovieType::classic :
        return stock[kClassicIndex].second.retrieve(*target, ret);
        break;

        default:
        
        cout << "MediaCollection::retrieve() | Unsupported Movie Type " << retrieve_type << endl;
        ret = nullptr;
        
        return false;
    }
}

void MediaCollection::display() const {
    
    const int kLineLength = 100;
    
    for (int i = 0; i < this->stock.size(); i++) {

        cout << setfill('-') << setw(kLineLength) << "" << setfill(' ') << endl;

        const Movie* movie = dynamic_cast<const Movie*>(stock[i].second.getRootValue()); 

        movie->PrintHeader();

        switch (stock[i].first) {

            case MovieType::comedy :
            stock[kComedyIndex].second.displayByLine();
            break;

            case MovieType::drama :
            stock[kDramaIndex].second.displayByLine();
            break;

            case MovieType::classic :
            stock[kClassicIndex].second.displayByLine();
            break;
        }
    }
}