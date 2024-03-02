#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include "../Movie/Movie.h"

using namespace std;

enum MediaType : char {

    dvd = 'D',
};

enum MovieType : char {

    comedy = 'F',
    drama = 'D',
    classic = 'C',
};

class Media {

 public: 
  
  // Constructor - Destructor
  Media();

  virtual ~Media() = 0;

  // Getters - Setters
  int getStock() const;
  virtual char getMediaType() const = 0;

  void setStock(const int amount);

  // Actions
  void addStock(const int amount);
  bool reduceStock(const int amount);

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Media& media);

  virtual bool operator < (const Media& rval) const = 0;
  virtual bool operator == (const Media& rval) const = 0;
 
 protected: 

  int stock;

  MediaType type;

  virtual void display(ostream& ostrm) const = 0;
};

#endif