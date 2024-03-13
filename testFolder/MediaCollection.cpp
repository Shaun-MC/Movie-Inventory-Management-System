#include "MediaCollection.h"

// Constructor
MediaCollection::MediaCollection() : kComedyIndex(0), kDramaIndex(1), kClassicIndex(2)  { 
    this->stock.push_back({MovieType::comedy, this->comedies});
    this->stock.push_back({MovieType::drama, this->dramas});
    this->stock.push_back({MovieType::classic, this->classics});
}

// Destructor
MediaCollection::~MediaCollection() {};

// Insert a media item into the collection
bool MediaCollection::Insert(Media*& media) { 
    char insert_type = dynamic_cast<Movie*>(media)->getMovieType();

    switch (insert_type) {
        case MovieType::comedy :
            return stock[kComedyIndex].second.Insert(media);
            break;

        case MovieType::drama :
            return stock[kDramaIndex].second.Insert(media);
            break;

        case MovieType::classic :
            return stock[kClassicIndex].second.Insert(media); 
            break;

        default:
        return false;
    }
}

// Retrieve a media item from the collection
bool MediaCollection::Retrieve(Media*& target, Media*& ret) { 
    char retrieve_type = dynamic_cast<const Movie*>(target)->getMovieType();

    switch (retrieve_type) {

        case MovieType::comedy :
            return stock[kComedyIndex].second.Retrieve(*target, ret);
            break;

        case MovieType::drama :
            return stock[kDramaIndex].second.Retrieve(*target, ret);
            break;

        case MovieType::classic :
            return stock[kClassicIndex].second.Retrieve(*target, ret);
            break;

        default:
            cout << "MediaCollection::Retrieve() | Unsupported Movie Type " << retrieve_type << endl;
            ret = nullptr;
        
        return false;
    }
}

// Display the contents of the media collection
void MediaCollection::Display() const {
    const int kLineLength = 100;
    
    for (int i = 0; i < this->stock.size(); i++) {
        cout << setfill('-') << setw(kLineLength) << " " << setfill(' ') << endl;

        Movie* movie = dynamic_cast<Movie*>(stock[i].second.getRootValue()); 

        movie->PrintHeader();

        switch (stock[i].first) {

            case MovieType::comedy :
            stock[kComedyIndex].second.DisplayByLine();
            break;

            case MovieType::drama :
            stock[kDramaIndex].second.DisplayByLine();
            break;

            case MovieType::classic :
            stock[kClassicIndex].second.DisplayByLine();
            break;
        }
    }
}