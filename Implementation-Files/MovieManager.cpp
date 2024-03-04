#include "MovieManager.h"

MovieManager::MovieManager() {}; // Member data intialize themsevles

void MovieManager::ReadCustomers(ifstream& customer_file) {

    if (!customer_file) {

        cout << "MovieManager::ReadCustomers() | Input File Could Not be Opened" << endl;
    }

    string line = "";

    while (!customer_file.eof()) {
        
        getline(customer_file, line);

        customers.receiveData(line);
    }
}

void MovieManager::ReadMovies(ifstream& movie_list) {

    if (!movie_list) {

        cout << "MovieManager::ReadMovies() | Input File Could Not Be Opened" << endl;
        return;
    }

    while (!movie_list.eof()) {

        string movie_line = "";

        getline(movie_list, movie_line);

        Media* new_media = MediaFactory::createDVDMovie(movie_line);

        if (new_media == nullptr) { // Do nothing - creating the Movie failed due to bad input

        // Unhandled Use Case: 2 Classic Movies's stock get 'combined'??
        } else if (!this->stocks.insert(new_media)) {  // Insertion fails because of a duplicate

            Media* dup_media = nullptr;
        
            this->stocks.retrieve(new_media, dup_media);

            dup_media->addStock(new_media->getStock());

            // Does dup_media get cleaned up??
        }

        // Does new_media get cleaned up??
    }  
}

void MovieManager::ReadTransactions(ifstream& transaction_list) {

    if (!transaction_list) {

        cerr << "MovieManager::ReadTransactions() | Input File Could Not Be Opened" << endl;
    }

    Transaction* new_trans = nullptr;

    while (!transaction_list.eof()) {

        string trans_line = "";

        getline(transaction_list, trans_line);   

        new_trans = TransactionFactory::createTransaction(trans_line);

        if (new_trans != nullptr) {

            new_trans->process(this->stocks, this->customers);

            delete new_trans;
            new_trans = nullptr;
        } 
    }
}

void MovieManager::displayCustomers() const {

    this->customers.display();
}

void MovieManager::displayMedia() const {

    this->stocks.display();
}