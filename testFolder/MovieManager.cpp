#include "MovieManager.h"

// Constructor 
MovieManager::MovieManager() {}; 

// Destructor
MovieManager::~MovieManager() {}; 

// Reads customer data from the provided file stream
void MovieManager::ReadCustomers(ifstream& customer_file) { 
    if (!customer_file) {
        cout << "MovieManager::ReadCustomers() | Input File Could Not be Opened" << endl;
    }

    string line = "";

    while (!customer_file.eof()) {
        getline(customer_file, line, '\n');
        customers.ReceiveData(line);
    }
}

// Reads movie data from the provided file stream
void MovieManager::ReadMovies(ifstream& movie_list) { 
    if (!movie_list) {
        cout << "MovieManager::ReadMovies() | Input File Could Not Be Opened" << endl;
        return;
    }

    while (!movie_list.eof()) {
        string movie_line = "";
        getline(movie_list, movie_line, '\n');

        Media* new_media = MediaFactory::CreateDVDMovie(movie_line);

        if (new_media == nullptr) { 
            continue;
        } 

        Classic* temp = dynamic_cast<Classic*>(new_media);

        if (temp == nullptr && !this->stocks.Insert(new_media)) { 
            Media* dup_media = nullptr;
        
            this->stocks.Retrieve(new_media, dup_media);
            dup_media->AddStock(new_media->getStock());

        } else {
            this->stocks.Insert(new_media);
        }
    }  
}

// Reads transaction data from the provided file stream
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

// Displays the list of customers
void MovieManager::DisplayCustomers() const {
    this->customers.Display();
}

// Displays the list of media
void MovieManager::DisplayMedia() const {
    this->stocks.Display();
}