#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"

class Drama : public Movie {

 public: 

  // Constructor - Destructor
  Drama();
  ~Drama();

  // Getter - Setters
  virtual bool setData(stringstream& movie_line);

  // Actions
  void PrintHeader() const;

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Drama& drama);

  bool operator < (const Media& rval) const;
  bool operator > (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 

  // Member Functions
  void Display(ostream& ostrm) const;
};

#endif 