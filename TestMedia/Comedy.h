#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"

class Comedy : public Movie {

 public: 

  // Constructor - Destructor
  Comedy();
  ~Comedy();

  // Getter - Setters
  int getYear() const;

  virtual bool setData(stringstream& movie_line);

  void setYear(const int year);

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Comedy& drama);

  bool operator < (const Media& rval) const;
  bool operator > (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 

  virtual void display(ostream& ostrm) const;

  bool getSetYear(stringstream& movie_line);

  int release_year;
};

#endif 