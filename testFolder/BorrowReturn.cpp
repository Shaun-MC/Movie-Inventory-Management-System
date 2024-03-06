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
    
    // Media *newMedia = nullptr
    char media_type = 0, movie_type = 0;

    this->entireTransaction = this->commandType + ' ';

    trans_line.ignore(); // Space

    // Reads and sets Customer ID Data 
    if (Transaction::setData(trans_line)) {

        this->ProcessInvalid(trans_line);
        return false;
    }  

    trans_line.ignore(); // Space 
    
    trans_line >> media_type; // Basic Course: D
    
    trans_line.ignore(); // Space

    this->entireTransaction += media_type + ' '; 

    switch(media_type){
        
        case MediaType::dvd :
            this->movie = new Movie();
            this->movie->setMediaType(dvd);
        break;

        default: 
        ProcessInvalid(trans_line);
        return false;
        break;
    }

    trans_line >> movie_type; // Basic Course: F, D or C 
    trans_line.ignore(); // Space

    this->entireTransaction += movie_type + ' '; 

    switch (movie_type) {

        case MovieType::comedy :
        //this->movie; // create new Comedy
        ProcessComedy(trans_line);
        break;

        case MovieType::classic :
        ProcessComedy(trans_line);
        break;

        case MovieType::drama :
        ProcessDrama(trans_line);
        break;

        default: 
        ProcessInvalid(trans_line);
        return false;
        break;
    }
    
    return true;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BorrowReturn::ProcessComedy(stringstream& trans_line){ // DONE
    
    // Intialize Sorting Criteria variables
    string title = ""; 
    int year = 0;

    // Get & Set the Movies Title
    getline(trans_line, title, ',');
    trans_line.ignore(); // Space
    
    dynamic_cast<Movie*>(this->movie)->setTitle(title);

    // Get & Set the Movies Release Year
    trans_line >> year;
    dynamic_cast<Movie*>(this->movie)->setYear(year);

    // Add to transaction string
    entireTransaction += title + ", " + to_string(year);
}

void BorrowReturn::ProcessDrama(stringstream& trans_line){ // UNTESTED

    // Intialize Sorting Criteria variables
    string title = "", director = "";
    
    // Get & Set the Movies Title
    getline(trans_line, director, ',');
    trans_line.ignore(); // Space

    dynamic_cast<Movie*>(this->movie)->setDirector(director);
    trans_line.ignore(); // Space

	// Get & Set the Movies Title
	getline(trans_line, title, '\n');
    dynamic_cast<Movie*>(this->movie)->setTitle(title);

	// Add to transaction string
	entireTransaction += director + ", " + title + ", ";
}

void BorrowReturn::ProcessClassic(stringstream& trans_line){ // UNTESTED
    
    // Intialize Sorting Criteria variables
    int month = 0, year = 0; 
    string majorActor = "";

    // Get & Set the Release Month and Release Year 
    trans_line >> month >> year; // Need to Error Check??
	
    dynamic_cast<Classic*>(this->movie)->setReleaseMonth(month);
    dynamic_cast<Movie*>(this->movie)->setYear(year);

	trans_line.ignore(); // Space

    // Get & Set the Major Actor 
    getline(trans_line, majorActor, '\n');
	
    dynamic_cast<Classic*>(this->movie)->InsertMajorActor(majorActor, this->movie->getStock()); 

    // Add to transaction string
	entireTransaction += to_string(month) + ' ' + to_string(year) + ' ' + majorActor;
}

// If called in movie_type switch statment, movie type is not included
// If called from setData conditional, cust_id not included
void BorrowReturn::ProcessInvalid(stringstream& trans_line){ // UNTESTED
    
    string temp = "";

    // Get the rest of trans_line
	getline(trans_line, temp, '\n');
	
    this->entireTransaction += temp;

	cerr << "BorrowReturn::ProcessInvalid() | Invalid Command: " << this->entireTransaction << endl;
}
