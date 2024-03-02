#ifndef MOVIE_H
#define MOVIE_H

#include <sstream>
#include "../Media/Media.h"

class Movie : public Media {

 public: 

  // Constructor - Destructor
  Movie();
  virtual ~Movie();

  // Getter - Setters
  string getTitle() const;
  int getYear() const;
  string getDirector() const;
  
  virtual bool setData(stringstream& movie_line);

  void setTitle(string title);
  int setYear(int year);
  void setDirector(string f_name, string l_name);

  virtual char getMediaType() const;
  virtual char getMovieType() const; 

  // Operator Overloading
  friend ostream& operator << (ostream& ostrm, const Movie& obj);

  virtual bool operator < (const Media& rval) const = 0;
  virtual bool operator == (const Media& rval) const = 0;
 
 protected: 
  
  char movieType; 
  
  string director;
  
  string title;
  
  int release_year;

  bool getSetStock(stringstream& movie_line);
  bool getSetDirector(stringstream& movie_line);
  bool getSetTitle(stringstream& movie_line);
  bool getSetYear(stringstream& movie_line);

  virtual void display(ostream& ostrm) const = 0;
};

#endif