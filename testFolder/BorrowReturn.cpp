#include "BorrowReturn.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
BorrowReturn::BorrowReturn(){ // DONE
    
    this->customerID = 0;
    this->movie = nullptr;
}

BorrowReturn::~BorrowReturn(){ // DONE
    
    if (this->movie != nullptr) {
		
        delete this->movie;
		this->movie = nullptr;
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Getter - Setter
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Uses early returns for boolean return
bool BorrowReturn::setData(stringstream& trans_line){ // UNTESTED
    
    Media *newMedia = nullptr;
    char media_type = 0, movie_type = 0;

    switch (this->commandType) {

        case CommandType::borrow : 
        this->transactionLog += "Borrowed";
        break;

        case CommandType::return_ :
        this->transactionLog += "Returned";
        break;
    }

    trans_line.ignore(); // Space

    // Reads and sets Customer ID Data 
    if (Transaction::setData(trans_line)) {

        this->ProcessInvalid(trans_line);
        return false;
    }  

    trans_line.ignore(); // Space 
    
    trans_line >> media_type; // Basic Course: D
    
    trans_line.ignore(); // Space

    switch(media_type){
        
        case MediaType::dvd :
        this->media_type = dvd;
        break;

        default: 
        ProcessInvalid(trans_line);
        return false;
        break;
    }

    trans_line >> movie_type; // Basic Course: F, D or C 
    trans_line.ignore(); // Space

    switch (movie_type) {

        case MovieType::comedy :
        ProcessComedy(trans_line, newMedia);
        break;

        case MovieType::classic :
        ProcessComedy(trans_line, newMedia);
        break;

        case MovieType::drama :
        ProcessDrama(trans_line, newMedia);
        break;

        default: 
        ProcessInvalid(trans_line);
        return false;
        break;
    }

    this->movie = newMedia;
    
    return true;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BorrowReturn::ProcessComedy(stringstream& trans_line, Media*& newMedia){ // DONE
    
    this->movie_type = MovieType::comedy;
    newMedia = new Comedy();

    // Intialize Sorting Criteria variables    
    string title = ""; 
    int year = 0;

    // Get & Set the Movies Title
    getline(trans_line, title, ',');
    trans_line.ignore(); // Space
    
    dynamic_cast<Comedy*>(newMedia)->setTitle(title);

    // Get & Set the Movies Release Year
    trans_line >> year;
    dynamic_cast<Comedy*>(newMedia)->setYear(year);

    // Add to transaction string
    this->transactionLog += ' ' + dynamic_cast<Comedy*>(newMedia)->getTitle();
}

void BorrowReturn::ProcessDrama(stringstream& trans_line, Media*& newMedia){ // UNTESTED

    this->movie_type = MovieType::drama;
    newMedia = new Drama();

    // Intialize Sorting Criteria variables
    string title = "", director = "";
    
    // Get & Set the Movies Title
    getline(trans_line, director, ',');
    trans_line.ignore(); // Space

    dynamic_cast<Drama*>(newMedia)->setDirector(director);
    trans_line.ignore(); // Space

	// Get & Set the Movies Title
	getline(trans_line, title, '\n');
    dynamic_cast<Drama*>(newMedia)->setTitle(title);

	// Add to transaction string
	this->transactionLog += ' ' + dynamic_cast<Drama*>(newMedia)->getTitle();
}

void BorrowReturn::ProcessClassic(stringstream& trans_line, Media*& newMedia){ // UNTESTED
    
    this->movie_type = MovieType::classic;
    newMedia = new Drama();

    // Intialize Sorting Criteria variables
    int month = 0, year = 0; 
    string majorActor = "";

    // Get & Set the Release Month and Release Year 
    trans_line >> month >> year; // Doesn't Error Check
	
    dynamic_cast<Classic*>(newMedia)->setReleaseMonth(month);
    dynamic_cast<Classic*>(newMedia)->setYear(year);

	trans_line.ignore(); // Space

    // Get & Set the Major Actor 
    getline(trans_line, majorActor, '\n');
	
    dynamic_cast<Classic*>(newMedia)->InsertMajorActor(majorActor, this->movie->getStock()); 

    // Add to transaction string
	this->transactionLog += ' ' + dynamic_cast<Classic*>(newMedia)->getTitle();
}

// If called in movie_type switch statment, movie type is not included
// If called from setData conditional, cust_id not included
void BorrowReturn::ProcessInvalid(stringstream& trans_line){ // UNTESTED
    
    string temp = "";

    // Get the rest of trans_line
	getline(trans_line, temp, '\n');
	
    this->transactionLog += temp;

	cerr << "BorrowReturn::ProcessInvalid() | Invalid Command: " << this->transactionLog << endl;
}
