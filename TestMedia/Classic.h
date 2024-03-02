#ifndef CLASSIC_H
#define CLASSIC_H

#include "Movie.h"

class Classic : public Movie {

 public: 

  // Constructor - Destructor
  Classic();
  ~Classic();

  // Getters - Setters
  string getMajorActor() const;
  string getReleaseDate() const;

  virtual bool setData(stringstream& movie_line);

  void setMajorActor(const string name);
  void setReleaseDate(const string date);

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Classic& drama);

  bool operator < (const Media& rval) const;
  bool operator > (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 

  string major_actor;
  string release_date;
  
  bool getSetMA(stringstream& movie_line);
  bool getSetDate(stringstream& movie_line);

  virtual void display(ostream& ostrm) const;
};

#endif 