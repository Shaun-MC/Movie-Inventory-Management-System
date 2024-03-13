#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <iomanip>
using namespace std;

// Enumeration for media types
enum MediaType : char {
    dvd = 'D',
    DefaultMediaType = ' '
};

// Enumeration for movie types
enum MovieType : char {
    comedy = 'F',
    drama = 'D',
    classic = 'C',
    DefaultMovieType = ' '
};

class Media {
 public: 
  // Constructor 
  Media();

  // Destructor
  virtual ~Media();

  // Getters - Setters
  int getStock() const;
  virtual char getMediaType() const = 0;
  void setStock(const int amount);
  void setMediaType(const MediaType type);

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