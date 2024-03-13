#ifndef MOVIE_CLASSIC_H
#define MOVIE_CLASSIC_H
#include <map>
#include "Movie.h"

class Classic : public Movie {
 public: 
  // Constructor 
  Classic();
  // Destructor
  ~Classic();

  // Getters - Setters
  string getMajorActor() const;
  int getReleaseMonth() const;
  virtual bool setData(stringstream& movie_line);
  void setReleaseMonth(const int month);

  // Actions
  void PrintHeader() const;
  void InsertMajorActor(const string name, const int stock_amount);
  void Merge(Classic* rval);
  void IncrementStock(const string actor_name);
  bool DecrementStock(const string actor_name);

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Classic& drama);
  bool operator < (const Media& rval) const;
  bool operator > (const Media& rval) const;
  bool operator == (const Media& rval) const;

 private: 
  // Member Functions
  bool CompareMajorActors(const string& actor) const;
  bool GetSetMA(stringstream& movie_line);
  bool GetSetMonth(stringstream& movie_line);
  virtual void Display(ostream& ostrm) const;

  // Member Data
  int release_month;
  map<string, int> major_actors; // Insertion Keeps it sorted
};

#endif 