#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iomanip>

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

  void setMediaType(const char type);

  // Actions
  void AddStock(const int amount);
  void IncrementStock();
  bool DecrementStock();

  // Operator Overloads
  friend ostream& operator << (ostream& ostrm, const Media& media);

  virtual bool operator < (const Media& rval) const = 0;
  virtual bool operator > (const Media& rval) const = 0;
  virtual bool operator == (const Media& rval) const = 0;
 
 protected: 

  // Member Function
  virtual void Display(ostream& ostrm) const = 0;
  
  // Member Data
  int stock;

  char type;
};

#endif