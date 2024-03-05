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

  // Actions
  void PrintHeader() const;

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Comedy& drama);

  bool operator < (const Media& rval) const;
  bool operator > (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 

  virtual void display(ostream& ostrm) const;
};

#endif 