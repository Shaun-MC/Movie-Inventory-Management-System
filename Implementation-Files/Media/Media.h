#ifndef MEDIA_H
#define MEDIA_H

#include <string>

using namespace std;

enum MediaType : char {

    dvd = 'D',
    DefaultMediaType = ' '
};

enum MovieType : char {

    comedy = 'F',
    drama = 'D',
    classic = 'C',
    DefaultMovieType = ' '
};

class Media {

 public: 
  
  // Constructor - Destructor
  Media();

  virtual ~Media();

  // Getters - Setters
  int getStock() const;
  virtual char getMediaType() const = 0;

  void setStock(const int amount);

  // Actions
  void addStock(const int amount);
  void incrementStock();
  bool decrementStock();

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Media& media);

  virtual bool operator < (const Media& rval) const = 0;
  virtual bool operator > (const Media& rval) const = 0;
  virtual bool operator == (const Media& rval) const = 0;
 
 protected: 

  int stock;

  MediaType type;

  virtual void display(ostream& ostrm) const = 0;
};

#endif