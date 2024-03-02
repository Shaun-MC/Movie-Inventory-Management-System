#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"

class Drama : public Movie {

 public: 

  // Constructor - Destructor
  Drama();
  ~Drama();

  // Getter - Setters
  int getYear() const;

  virtual bool setData(stringstream& movie_line);

  void setYear(const int year);

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Drama& drama);

  bool operator < (const Media& rval) const;
  bool operator > (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 

  void display(ostream& ostrm) const;

  bool getSetYear(stringstream& movie_line);

  int release_year;
};

#endif 