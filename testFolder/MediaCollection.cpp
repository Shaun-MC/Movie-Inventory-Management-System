#include "MediaCollection.h"
#include <vector>

// Constructor - Destructor
MediaCollection::MediaCollection() { // DONE

    // Each insert also calls the AVLTree destructor
    this->stock.insert( pair<char, AVLTree<Media> >(MovieType::comedy, comedies) ); 

    this->stock.insert( pair<char, AVLTree<Media> >(MovieType::drama, dramas) );

    this->stock.insert( pair<char, AVLTree<Media> >(MovieType::classic, classics) );
}

MediaCollection::~MediaCollection() {}

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

void MediaCollection::display() const {
    const int kLineLength = 100;

    // Copy the keys into a vector
    std::vector<char> genres;
    for (const auto& pair : this->stock) {
        genres.push_back(pair.first);
    }

    // Iterate through the vector in reverse order
    for (auto it = genres.rbegin(); it != genres.rend(); ++it) {
        char genre = *it;

        cout << setfill('-') << setw(kLineLength) << '-' << endl;
        cout << setfill(' ');

        switch (genre) {
            case 'F':
                cout << "Comedies:" << endl;
                break;
            case 'D':
                cout << "Dramas:" << endl;
                break;
            case 'C':
                cout << "Classics:" << endl;
                break;
            // No default
        }

        cout << left << setw(8) << "Genre" << setw(8) << "Media" << setw(37) << "Title" << setw(25) <<
            "Director" << setw(8) << "Year" << "Stock" << endl;

        this->stock.at(genre).displayByLine();
    }
}


// void MediaCollection::display() const {

//     const int kLineLength = 100;

//     for (auto pair : this->stock) {

//         cout << setfill('-') << setw(kLineLength) << '-' << endl;
//         cout << setfill(' ');

//         switch(pair.first) {

//             case 'F':
//             cout << "Comedies:" << endl;
//             break;

//             case 'D':
//             cout << "Dramas:" << endl;
//             break;

//             case 'C':
//             cout << "Classics:" << endl;
//             break;

//             // No default
//         }

//         cout << endl;

//         cout << left << setw(8) << "Genre" << setw(8) << "Media" << setw(37) << "Title" << setw(25) << 
//             "Director" << setw(8) << "Year" << "Stock" << endl;

//         pair.second.displayByLine();
//     }
// }



/*void MediaCollection::displayTree() const { // DONE

    for (auto pair : this->stock) {

        cout << pair.first << endl;
        pair.second.displayTree();
    }
}*/

