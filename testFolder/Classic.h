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
  int getReleaseMonth() const;

  virtual bool setData(stringstream& movie_line);

  void setMajorActor(const string f_name, const string l_name);
  void setReleaseMonth(const int month);

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Classic& drama);

  bool operator < (const Media& rval) const;
  bool operator > (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 

  string major_actor;
  int release_month;
  
  bool getSetMA(stringstream& movie_line);
  bool getSetMonth(stringstream& movie_line);

  //virtual string reconstructLine() const;

  virtual void display(ostream& ostrm) const;
};

#endif 