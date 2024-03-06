#ifndef MEDIACOLLECTION_H
#define MEDIACOLLECTION_H

#include "AVLTree.h"
#include "MediaFactory.h"

#include <vector>

class MediaCollection { 

 public:
  
  // Constructor - Destructor
  MediaCollection();

  ~MediaCollection();
  
  // Actions
  bool Insert(Media*& insert_media);

  bool Retrieve(Media*& target, Media*& ret);

  void Display() const;

 private:

  // Underlieing Data Structure - Dictionary
  // Key: Type of Movie (Only Dvd's for this proj.)
  // Value: AVLTree Storing the movies related to that type

  vector< pair<char, AVLTree> > stock;

  AVLTree comedies;
  AVLTree dramas;
  AVLTree classics;

  const int kComedyIndex;
  const int kDramaIndex;
  const int kClassicIndex;
};

#endif