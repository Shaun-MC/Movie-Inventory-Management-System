#ifndef MEDIACOLLECTION_H
#define MEDIACOLLECTION_H

#include <map>

#include "Media.h"

#include "AVLTree.h"
#include "MediaFactory.h"

// Idea: Make it a Singleton
class MediaCollection { 

 public:
  
  // Constructor - Destructor
  MediaCollection();

  ~MediaCollection();
  
  // Actions
  bool insert(Media*& insert_media);

  bool retrieve(Media*& target, Media*& ret);
 
 private:

  // Underlieing Data Structure - Dictionary - Future Iterations
  // Key: Type of Media (Only Dvd's for this proj.)
  // Value: 
    // Key: Type of Movie (Only Comedies, Dramas, or Classics for this proj)
    // Value: AVLTree Storing the movies related to that type
  map<char, AVLTree<Media> > stock;
  
  AVLTree<Media> comedies;
  AVLTree<Media> dramas;
  AVLTree<Media> classics;

  // Private Memeber Functions
  void clear();
};

#endif