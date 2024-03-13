#include "Transaction_BorrowReturn.h"

// Constructor 
BorrowReturn::BorrowReturn(){ 
    this->customerID = 0;
    this->movie = nullptr;
}

// Destructor
BorrowReturn::~BorrowReturn(){ 
    if (this->movie != nullptr) {
		
        delete this->movie;
		this->movie = nullptr;
	}
}

// Set transaction data from a stringstream
bool BorrowReturn::setData(stringstream& trans_line){ 
    
    Media *newMedia = nullptr;
    char input_media_type = 0, input_movie_type = 0;

    switch (this->commandType) {

        case CommandType::borrow : 
        this->transactionLog += "Borrowed";
        break;

        case CommandType::return_ :
        this->transactionLog += "Returned";
        break;
    }

    if (!Transaction::setData(trans_line)) {

        this->ProcessInvalid(trans_line, 1);
        return false;
    }  

    trans_line.ignore();  
    trans_line >> input_media_type; 
    trans_line.ignore(); 

    switch(input_media_type){

        case MediaType::dvd :
        this->media_type = MediaType::dvd;
        break;

        default: 
        this->media_type = input_media_type;
        ProcessInvalid(trans_line, 2); 
        return false;
        break;
    }

    trans_line >> input_movie_type; 
    trans_line.ignore();

    switch (input_movie_type) {

        case MovieType::comedy :
        ProcessComedy(trans_line, newMedia);
        break;

        case MovieType::drama :
        ProcessDrama(trans_line, newMedia);
        break;

        case MovieType::classic :
        ProcessClassic(trans_line, newMedia);
        break;

        default: 
        this->movie_type = input_movie_type; 
        ProcessInvalid(trans_line, 3); 
        return false;
        break;
    }

    this->movie = newMedia;
    
    return true;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BorrowReturn::ProcessComedy(stringstream& trans_line, Media*& newMedia){ 
    this->movie_type = MovieType::comedy;
    newMedia = new Comedy(); 

    string title = ""; 
    int year = 0;

    getline(trans_line, title, ',');
    trans_line.ignore();
    
    dynamic_cast<Comedy*>(newMedia)->setTitle(title); 

    trans_line >> year;
    dynamic_cast<Comedy*>(newMedia)->setYear(year);

    this->transactionLog += ' ' + dynamic_cast<Comedy*>(newMedia)->getTitle();
}

void BorrowReturn::ProcessDrama(stringstream& trans_line, Media*& newMedia){ 

    this->movie_type = MovieType::drama;
    newMedia = new Drama(); 

    string title = "", director = "";

    getline(trans_line, director, ',');
    trans_line.ignore();

    dynamic_cast<Drama*>(newMedia)->setDirector(director);

	getline(trans_line, title, ',');
    dynamic_cast<Drama*>(newMedia)->setTitle(title);

	this->transactionLog += ' ' + dynamic_cast<Drama*>(newMedia)->getTitle();
}

void BorrowReturn::ProcessClassic(stringstream& trans_line, Media*& newMedia){ 
    
    this->movie_type = MovieType::classic;
    newMedia = new Classic(); 

    int month = 0, year = 0; 
    string majorActor = "";

    trans_line >> month >> year; 
	
    dynamic_cast<Classic*>(newMedia)->setReleaseMonth(month);
    dynamic_cast<Classic*>(newMedia)->setYear(year);

	trans_line.ignore();

    getline(trans_line, majorActor, '\n');
	
    dynamic_cast<Classic*>(newMedia)->InsertMajorActor(majorActor, 1); 
}

void BorrowReturn::ProcessInvalid(stringstream& trans_line, const int flag){ 
    switch(flag) {
        case 1: 
            cerr << "Error: " << this->getCustomerID() << " Invalid Customer ID. Try Again." << endl;
            break;

        case 2: 
            cerr << "Error: " << this->media_type << " Invalid Media Type. Try Again." << endl;
            break;

        case 3:
            cerr << "Error: " << this->movie_type << " Invalid Genre. Try Again." << endl;
            break;
    }
}
