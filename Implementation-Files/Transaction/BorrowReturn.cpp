#include "BorrowReturn.h"

BorrowReturn::BorrowReturn(){
    this->customerID = 0;
    this->Media_type = DefaultMediaType;
    this->movie_type = DefaultMovieType;
    this->movie = nullptr;

}

BorrowReturn::~BorrowReturn(){
    if (this->movie != nullptr) {
		delete this->movie;
		this->movie = nullptr;
	}
}

bool BorrowReturn::setData(ifstream &file){
    Media *newMedia = nullptr;

    char media_data, movie_data;
    string id_data;

    entireTransaction = this->commandType;
    entireTransaction += ' ';

    file.ignore();
    file >> id_data;
    entireTransaction += id_data;
    entireTransaction += ' ';

    stringstream convert(id_data);
    convert >> this->customerID;

    if(convert.fail() || customerID < 0){
        processInvalid(file, id_data, string("customer ID"));
        return false;
    }

    file.ignore();
    file >> media_data;

    entireTransaction += media_data;
    entireTransaction += ' ';

    switch(media_data){
        case dvd:
            this->Media_type = dvd;
            file.ignore();
            file >> movie_data;

            entireTransaction += movie_data;
            entireTransaction += ' ';

            switch(movie_data){
                case comedy:
                    processComedy(file, newMedia);
                    break;

                case classic:
                    processClassic(file, newMedia);
                    break;
                
                case drama:
                    processDrama(file, newMedia);
                    break;
                default:
			        processInvalid(file,
				    string().insert(0, 1, movie_data),
				    string("movie type"));
			        break;
		        }
		        break;
        default:
		    processInvalid(file,
			string().insert(0, 1, media_data),
			string("media type"));
		    break;
    }

    file.clear();
    this->movie = newMedia;
    bool isValid = this->movie != nullptr ? isValid = true : isValid = false;
    return isValid;

}

void BorrowReturn::processDrama(ifstream &moviedata, Media *&movie){
    this->movie_type = drama;
	movie = new Drama();
	string title, director;

	// set media director
	moviedata.ignore();
	getline(moviedata >> ws, director, ',');
	dynamic_cast<Drama*>(movie)->setDirector(director);

	// set media title
	moviedata.ignore();
	getline(moviedata >> ws, title, ',');
	dynamic_cast<Drama*>(movie)->setTitle(title);

	// add to command
	entireTransaction += director + ", " + title + ", ";
}

void BorrowReturn::processClassic(ifstream &moviedata, Media *&movie){
    this->movie_type = classic;
	movie = new Classic();
	string actorname;
	int month, year;

	moviedata.ignore();
	moviedata >> month;
	dynamic_cast<Classic*>(movie)->setReleaseMonth(month);

	moviedata.ignore();
	moviedata >> year;
	dynamic_cast<Classic*>(movie)->setYear(year);

	moviedata.ignore();
	moviedata >> actorname;
	dynamic_cast<Classic*>(movie)->setMajorActor(actorname, " "); // ?? not sure how to break first, last name

	entireTransaction += to_string(month) + ' ' + to_string(year) + ' ' + actorname;
}

void BorrowReturn::processComedy(ifstream &moviedata, Media *&movie){
    this->movie_type = comedy;
    movie = new Comedy();
    string title; 
    int year;

    moviedata.ignore();
    moviedata >> year;
    dynamic_cast<Comedy*>(movie)->setTitle(title);

    moviedata.ignore();
    moviedata >> year;
    dynamic_cast<Comedy*>(movie)->setYear(year);

    entireTransaction += title + ", " + to_string(year);
}

void BorrowReturn::processInvalid(ifstream &file, const string &customer_id, const string &name){
    string temp;
	file.ignore();
	getline(file, temp, '\n');
	this->entireTransaction += temp;

	// print out error
	cerr << "Command, invalid " << name << " '" << customer_id << "':" << '\n' << "  " << this->entireTransaction << endl;
}
