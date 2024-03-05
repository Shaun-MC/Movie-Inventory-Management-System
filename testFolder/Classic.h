#ifndef CLASSIC_H
#define CLASSIC_H

#include <map>
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

  void setReleaseMonth(const int month);

  // Actions
  void InsertMajorActor(const string name, const int stock_amount);

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Classic& drama);

  bool operator < (const Media& rval) const;
  bool operator > (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 

  int release_month;

  map<string, int> major_actors; // Insertion Keeps it sorted
  //vector<pair <string, int> > major_actors; // Not a good name
  
  bool getSetMA(stringstream& movie_line);
  bool getSetMonth(stringstream& movie_line);

  //virtual string reconstructLine() const;

  virtual void display(ostream& ostrm) const;
};

#endif 