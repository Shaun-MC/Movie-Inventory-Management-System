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
    char input_media_type = 0, input_movie_type = 0;

    switch (this->commandType) {

        case CommandType::borrow : 
        this->transactionLog += "Borrowed";
        break;

        case CommandType::return_ :
        this->transactionLog += "Returned";
        break;
    }

    // Reads and sets Customer ID Data 
    if (!Transaction::setData(trans_line)) {

        this->ProcessInvalid(trans_line, 1);
        return false;
    }  

    trans_line.ignore(); // Space 
    
    trans_line >> input_media_type; // Basic Course: D
    
    trans_line.ignore(); // Space

    switch(input_media_type){
        
        this->media_type = input_media_type; // Bad practice - intentionally storing bad data

        case MediaType::dvd :
        break;

        default: 
        ProcessInvalid(trans_line, 2); // Invalid Media 
        return false;
        break;
    }

    trans_line >> input_movie_type; // Basic Course: F, D or C 
    trans_line.ignore(); // Space

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
        this->movie_type = input_movie_type; // Bad Practice - intentionally storing bad data, rename / redeisgn if time allows
        ProcessInvalid(trans_line, 3); // Invalid Movie Type
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
    
    dynamic_cast<Comedy*>(newMedia)->setTitle(title); // Sets the Director instead

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

	// Get & Set the Movies Title
	getline(trans_line, title, ',');
    dynamic_cast<Drama*>(newMedia)->setTitle(title);

	// Add to transaction string
	this->transactionLog += ' ' + dynamic_cast<Drama*>(newMedia)->getTitle();
}

void BorrowReturn::ProcessClassic(stringstream& trans_line, Media*& newMedia){ // UNTESTED
    
    this->movie_type = MovieType::classic;
    newMedia = new Classic();

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
	
    dynamic_cast<Classic*>(newMedia)->InsertMajorActor(majorActor, 1); 

    // Add to transaction string
	//this->transactionLog += ' ' + dynamic_cast<Classic*>(newMedia)->getTitle(); // Doesn't Have a Title Hear
}

// If called in movie_type switch statment, movie type is not included
// If called from setData conditional, cust_id not included
void BorrowReturn::ProcessInvalid(stringstream& trans_line, const int flag){ // UNTESTED
    
    //string temp = "";
    switch(flag) {

        case 1: 
            cerr << "Error: " << this->getCustomerID() << " Invalid Customer ID. Try Again." << endl;
            //cerr << "BorrowReturn::ProcessInvalid() | Invalid Customer ID: " << this->getCustomerID() << endl;
        break;

        case 2: 
            cerr << "Error: " << this->media_type << " Invalid Media Type. Try Again." << endl;
            //cerr << "BorrowReturn::ProcessInvalid() | Invalid Media Type: " << this->media_type << endl;
        break;

        case 3:
            cerr << "Error: " << this->movie_type << " Invalid Genre. Try Again." << endl;
            //cerr << "BorrowReturn::ProcessInvalid() | Invalid Movie Type: " << this->movie_type << endl;
        break;

        // No default
    }
}
