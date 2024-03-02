#ifndef STOCKCOLLECTION_H
#define STOCKCOLELCTION_H

#include <map>

#include "Media.h"
#include "MediaFactory.h"

#include "../Data Structures/AVLTree.h"

// Singleton??
class MediaCollection { 

 public:
  
  // Destructor
  ~MediaCollection();

  // Getter
  static MediaCollection* getCollection();
  
  // Actions
  bool insertMedia(const Media*& insert_media);

  bool retrieve(const Media*& target, Media*& ret);

  MediaFactory factory;
 
 private:

  // Singleton Pattern Requirements
  static MediaCollection* instancePtr;

  MediaCollection();

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

MediaCollection* MediaCollection::instancePtr = nullptr;

#endif