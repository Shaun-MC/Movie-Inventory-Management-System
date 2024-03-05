#ifndef MEDIACOLLECTION_H
#define MEDIACOLLECTION_H

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

  void display() const;

  //void displayTree() const; // Debugging Purposes
 
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

  // Private Memeber Functions
  //void clear();
};

#endif