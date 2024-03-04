#ifndef MEDIACOLLECTION_H
#define MEDIACOLLECTION_H

#include <unordered_map>

#include "AVLTree.h"

#include "Media.h"
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

  void display() const;

  //void displayTree() const; // Debugging Purposes
 
 private:

  // Underlieing Data Structure - Dictionary
  // Key: Type of Movie (Only Dvd's for this proj.)
  // Value: AVLTree Storing the movies related to that type

  unordered_map<char, AVLTree<Media> > stock;
  
  AVLTree<Media> comedies;
  AVLTree<Media> dramas;
  AVLTree<Media> classics;

  // Private Memeber Functions
  void clear();
};

#endif