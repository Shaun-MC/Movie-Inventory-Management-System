#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"

class Comedy : public Movie {

 public: 

  // Constructor - Destructor
  Comedy();
  ~Comedy();

  // Setter
  virtual bool setData(stringstream& movie_line);

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Comedy& drama);

  bool operator < (const Media& rval) const;
  bool operator > (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 

  string reconstructLine() const;

  virtual void display(ostream& ostrm) const;
};

#endif 