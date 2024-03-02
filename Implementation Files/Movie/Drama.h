#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"

class Drama : public Movie {

 public: 

  // Constructor - Destructor
  Drama();
  ~Drama();

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Drama& drama);

  bool operator < (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 

  void display(ostream& ostrm) const;
};

#endif 