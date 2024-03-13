#include "Classic.h"

// Constructor
Classic::Classic() : release_month(0) { 
    this->movieType = MovieType::classic;
    this->stock = 0;
    this->title = this->director = "";
}

// Destructor
Classic::~Classic() {}

// Get the name of the major actor
string Classic::getMajorActor() const { 
    return this->major_actors.begin()->first;
}

// Get the release month of the classic movie
int Classic::getReleaseMonth() const {
    return this->release_month;
}

// Set data for the Classic movie
bool Classic::setData(stringstream& movie_line) { 
    return (!Movie::setData(movie_line) ||
            (!this->GetSetMA(movie_line) ||
            !this->GetSetMonth(movie_line) || 
            !Movie::GetSetYear(movie_line))
           ) ? false : true;
}

// Set the release month of the classic movie
void Classic::setReleaseMonth(const int date)  {
    this->release_month = date;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Print header for classics
void Classic::PrintHeader() const {
    cout << "Classics: " << endl << endl;
    cout << left << setw(8) << "Genre" << setw(8) << "Media" << setw(37) << "Title" << setw(25) <<
            "Director" << setw(8) << "Month" << setw(8) << "Year" << "Stock" << endl;
}

// Insert a major actor into the classic movie
void Classic::InsertMajorActor(const string name, const int stock_amount) {
    this->major_actors.insert({name, stock_amount});
}

// Merge another classic movie into this one
void Classic::Merge(Classic* rval) {
    this->InsertMajorActor(rval->getMajorActor(), rval->getStock());
    this->AddStock(rval->getStock());
}

// Increment stock for a specific major actor
void Classic::IncrementStock(const string actor_name) {
    if (this->major_actors.find(actor_name) != this->major_actors.end()) {
        ++this->stock;
        ++this->major_actors.at(actor_name);
    }
}

// Decrement stock for a specific major actor
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

// Overloaded output stream operator for Classic movie
ostream& operator << (ostream& ostrm, const Classic& classic) {
    classic.Display(ostrm);
    return ostrm;
}

// Comparison operator for less than
bool Classic::operator < (const Media& rval) const { 
    if (this->getYear() != dynamic_cast<const Classic& >(rval).getYear()) {
        return this->getYear() < dynamic_cast<const Classic& >(rval).getYear();
    }

    if (this->getReleaseMonth() != dynamic_cast<const Classic& >(rval).getReleaseMonth()) {
        return this->getReleaseMonth() < dynamic_cast<const Classic& >(rval).getReleaseMonth();  
    }

    return this->getMajorActor() < dynamic_cast<const Classic& >(rval).getMajorActor();
}

// Comparison operator for greater than
bool Classic::operator > (const Media& rval) const {
    return (*this < rval || *this == rval) ? false : true;
}

// Comparison operator for equality
bool Classic::operator == (const Media& rval) const { 
    if (this->getDirector() == "" && this->getTitle() == "" && 
        (this->getYear() == dynamic_cast<const Classic&>(rval).getYear() && 
        this->getReleaseMonth() == dynamic_cast<const Classic&>(rval).getReleaseMonth() && 
        this->CompareMajorActors(dynamic_cast<const Classic&>(rval).getMajorActor()))) {
        return true;

    } else {
        return (this->getDirector() == dynamic_cast<const Classic&>(rval).getDirector() &&
                this->getTitle() == dynamic_cast<const Classic&>(rval).getTitle());

    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Private function to compare major actors
bool Classic::CompareMajorActors(const string& name) const {
    for (pair<string, int> element : this->major_actors) {
        if (name == element.first) {
            return true;
        }
    }
    return true;
}

// Private function to get and set major actors
bool Classic::GetSetMA(stringstream& movie_line) { 
    string f_name = "", l_name = "";
    string name = "";

    movie_line >> f_name >> l_name;
    movie_line.ignore(); 
    name = f_name + ' ' + l_name; 
    this->InsertMajorActor(name, this->stock);

    return true;
}

// Private function to get and set release month
bool Classic::GetSetMonth(stringstream& movie_line) {
    int month = 0;

    movie_line >> month;

    if (month <= 0) {
        return false;
    }

    movie_line.ignore(); 
    this->setReleaseMonth(month);

    return true;
}

// Display function to output classic movie information
void Classic::Display(ostream& ostrm) const { 
    ostrm << setw(8) << this->getMovieType() << setw(8) << this->getMediaType() << setw(37) << this->getTitle();
    ostrm << setw(25) << this->getDirector() << setw(8) << this->getReleaseMonth() << setw(8) << this->getYear(); 
    ostrm << this->getStock() << endl;

    for (auto pair : this->major_actors) {
        int dist = 78 - (55 + pair.first.length());

        ostrm << setw(55) << ' ' << pair.first;
        ostrm << setw(dist) << ' ' << setfill('-') << setw(2) << "" << setfill(' ');
        ostrm << setw(6) << ' ' << setfill('-') << setw(4) << "" << setfill(' ');
        ostrm << setw(4) << ' ' << pair.second << endl << left;
    }
}