#include "MovieManager.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MovieManager::MovieManager() {}; // Member data intialize themsevles

MovieManager::~MovieManager() {}; // Member data destruct themselves

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MovieManager::ReadCustomers(ifstream& customer_file) { // DONE

    if (!customer_file) {

        cout << "MovieManager::ReadCustomers() | Input File Could Not be Opened" << endl;
    }

    string line = "";

    while (!customer_file.eof()) {
        
        getline(customer_file, line, '\n');

        customers.ReceiveData(line);
    }
}

void MovieManager::ReadMovies(ifstream& movie_list) { // NOT DONE

    if (!movie_list) {

        cout << "MovieManager::ReadMovies() | Input File Could Not Be Opened" << endl;
        return;
    }

    while (!movie_list.eof()) {

        string movie_line = "";

        getline(movie_list, movie_line, '\n');

        Media* new_media = MediaFactory::CreateDVDMovie(movie_line);

        if (new_media == nullptr) { // Do nothing - creating the Movie failed due to bad input

            continue;
        } 

        // Classic Movie / Not Classic Movie
        // If new_media is not a Classic --> insert new_media
            // If that insert fails, add to the stock of the inserted movie 
            // Else new_media gets inserted (Basic Course)
        
        // Else - new_media is a Classic, and nothing happens if the insertion 'fails' because 
        //        the movie will get merged, adding the stock & M.A. to the orignial movie

        Classic* temp = static_cast<Classic*>(new_media);

        if (temp == nullptr && !this->stocks.Insert(new_media)) { 

            Media* dup_media = nullptr;
        
            this->stocks.Retrieve(new_media, dup_media);

            dup_media->AddStock(new_media->getStock());
        } else {

            this->stocks.Insert(new_media);
        }
    }  
}

void MovieManager::ReadTransactions(ifstream& transaction_list) { // UNTESTED

    if (!transaction_list) {

        cerr << "MovieManager::ReadTransactions() | Input File Could Not Be Opened" << endl;
    }

    while (!transaction_list.eof()) {

        Transaction* new_trans = nullptr;

        string trans_line = "";

        getline(transaction_list, trans_line, '\r');
        transaction_list.ignore(); // '\n' that doesn't get caught by the getline for some reason 

        new_trans = TransactionFactory::CreateTransaction(trans_line);

        if (new_trans != nullptr) {

            new_trans->Process(this->stocks, this->customers);

            new_trans = nullptr;    
        }
    }
}

void MovieManager::DisplayCustomers() const {

    this->customers.Display();
}

void MovieManager::DisplayMedia() const { // DONE

    this->stocks.Display();
}