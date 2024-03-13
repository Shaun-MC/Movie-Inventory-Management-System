#ifndef AVLTREE_H
#define AVLTREE_H

//Import
#include <iostream>
#include <iomanip>
#include "Media.h"
#include "Movie_Classic.h"
using namespace std;

class AVLTree {
 public: 
  // Constructors
  AVLTree();

  //Destructor
  ~AVLTree();
  
  // Getter
  Media* getRootValue() const;

  // Actions
  bool Insert(Media*& val);
  bool Retrieve(const Media& target, Media*& ret_val) const;
  void DisplayByLine() const;

 protected: 
  class TreeNode {

  public: 

   // Constructors
   TreeNode();
   TreeNode(Media& val);

   // Getters - Setters
   int getHeight() const;
   int getBalanceFactor() const;
   void setHeight(const int amount);

   // Actions
   void UpdateHeight();

    Media* value;
    TreeNode* left;
    TreeNode* right;
    int height;
  };

 private:
  
  // Getter 
  int getNodeCount() const;

  // Helper Functions
  TreeNode* InsertHelper(TreeNode*& currNode, Media*& val); 
  bool RetrieveHelper(TreeNode* currNode, const Media& target, Media*& ret_val) const;
  void ClearHelper(TreeNode*& delete_node);
  void DisplayByLineHelper(TreeNode* currNode) const;

  // Member Functions
  void Clear();
  void MakeRotation(const int bf, TreeNode*& curNode, Media*& val);
  void LeftLeftRotation(TreeNode*& U);
  void RightRightRotation(TreeNode*& U);
  void RightLeftRotation(TreeNode*& U);
  void LeftRightRotation(TreeNode*& U);

  // Member Data
  TreeNode* root;
  int nodeCount;
};

#endif