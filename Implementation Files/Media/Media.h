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
  virtual string getMediaType() const = 0;

  void setStock(const int amount);

  // Actions
  void addStock(const int amount);
  void reduceStock(const int amount);

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Media& media);
 
 protected: 

  int stock;

  MediaType type;

  virtual ostream& display(ostream& ostrm) const = 0;
};

#endif