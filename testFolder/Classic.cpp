#include "Classic.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Classic::Classic() : release_month(0) { // DONE

    this->movieType = MovieType::classic;

    this->stock = 0;

    this->title = this->director = "";
}

Classic::~Classic() {}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Getters - Setters
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Returns the first major actor in the map
string Classic::getMajorActor() const { // DONE

    return this->major_actors.begin()->first;
}

int Classic::getReleaseMonth() const { // DONE

    return this->release_month;
}

// Assumes stream is pointing to the stock value
bool Classic::setData(stringstream& movie_line) { // DONE

    // Execution Order only matters for the first function
    return (!Movie::setData(movie_line) ||
            (!this->GetSetMA(movie_line) ||
            !this->GetSetMonth(movie_line) || 
            !Movie::GetSetYear(movie_line))
           ) ? false : true;
}

void Classic::setReleaseMonth(const int date)  {

    this->release_month = date;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Classic::PrintHeader() const {

    cout << "Classics: " << endl << endl;

    cout << left << setw(8) << "Genre" << setw(8) << "Media" << setw(37) << "Title" << setw(25) <<
            "Director" << setw(8) << "Month" << setw(8) << "Year" << "Stock" << endl;
}

void Classic::InsertMajorActor(const string name, const int stock_amount) {

    this->major_actors.insert({name, stock_amount});
}

void Classic::Merge(Classic* rval) {

    // Add the rvals major actor to this classic Movie object - name + stock total
    this->InsertMajorActor(rval->getMajorActor(), rval->getStock());

    // Add the rvals stock totle to the total stock total
    this->AddStock(rval->getStock());
}


// Assumes the actor name exists 
void Classic::IncrementStock(const string actor_name) {

    if (this->major_actors.find(actor_name) != this->major_actors.end()) {

        ++this->stock;
        ++this->major_actors.at(actor_name);
    }
}

// Assumes the actor name exists 
bool Classic::DecrementStock(const string actor_name) {

    if (this->major_actors.find(actor_name) != this->major_actors.end() && 
        this->major_actors.at(actor_name) - 1 >= 0) {

        --this->stock;
        --this->major_actors.at(actor_name);

        return true;
    }

    return false;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Operator Overloads
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ostream& operator << (ostream& ostrm, const Classic& classic) {

    classic.Display(ostrm);

    return ostrm;
}

bool Classic::operator < (const Media& rval) const { // DONE

    // Sorting Criteria: Release Date & Headline Actor
    const Classic rval_temp = dynamic_cast<const Classic& >(rval);

    if (this->getYear() != rval_temp.getYear()) {

        return this->getYear() < rval_temp.getYear();
    }

    if (this->getReleaseMonth() != rval_temp.getReleaseMonth()) {

        return this->getReleaseMonth() < rval_temp.getReleaseMonth();  
    }

    return this->getMajorActor() < rval_temp.getMajorActor();
}

bool Classic::operator > (const Media& rval) const {

    return (*this < rval || *this == rval) ? false : true;
}

bool Classic::operator == (const Media& rval) const { // DONE

    const Classic rval_temp = dynamic_cast<const Classic& >(rval);

    if (this->getDirector() == "" && this->getTitle() == "" && 
        (this->getYear() == rval_temp.getYear() && 
        this->getReleaseMonth() == rval_temp.getReleaseMonth() && 
        this->CompareMajorActors(rval_temp.getMajorActor()))) {

            return true;
    } else {

        // Able to combine movie stocks if we know they're the same movie, the date is irrelevant here
        return (this->getDirector() == rval_temp.getDirector() &&
                this->getTitle() == rval_temp.getTitle());

    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Classic::CompareMajorActors(const string& name) const {

    for (pair<string, int> element : this->major_actors) {

        if (name == element.first) {

            return true;
        }
    }
    
    return true;
}

bool Classic::GetSetMA(stringstream& movie_line) { // DONE

    string f_name = "", l_name = "";
    string name = "";

    movie_line >> f_name >> l_name;
    
    movie_line.ignore(); // Space

    name = f_name + ' ' + l_name; 

    this->InsertMajorActor(name, this->stock);

    return true;
}

bool Classic::GetSetMonth(stringstream& movie_line) { // DONE

    int month = 0;

    movie_line >> month;

    if (month <= 0) {

        // Error Condition - Invalid Month
        return false;
    }
    movie_line.ignore(); // Space

    this->setReleaseMonth(month);

    return true;
}

void Classic::Display(ostream& ostrm) const { // DONE

    // Displays all non actor information
    ostrm << setw(8) << this->getMovieType() << setw(8) << this->getMediaType() << setw(37) << this->getTitle();
    
    ostrm << setw(25) << this->getDirector() << setw(8) << this->getReleaseMonth() << setw(8) << this->getYear(); 
        
    ostrm << this->getStock() << endl;
    
    // Display the Actor Name and the stock of movie associated w/ that actor 
    for (auto pair : this->major_actors) {

        // Distance from the laster letter of the actors name to where the month # is placed 
        int dist = 78 - (55 + pair.first.length());

        // Postion and Print the Actors Name - DONE
        ostrm << setw(55) << ' ' << pair.first;
        
        // Position and Print '-' characters for month - DONE
        ostrm << setw(dist) << ' ' << setfill('-') << setw(2) << "" << setfill(' ');

        // Position and Print '-' characters for year
        ostrm << setw(6) << ' ' << setfill('-') << setw(4) << "" << setfill(' ');

        // Position and Print stock value
        ostrm << setw(6) << right << pair.second << endl << left;
    }
}