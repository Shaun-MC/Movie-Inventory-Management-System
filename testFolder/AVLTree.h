#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <iomanip>

#include "Media.h"
#include "Classic.h"

using namespace std;


class AVLTree {

 public: 
  
  // Constructors - Destructor
  AVLTree();
  //AVLTree(const AVLTree& rval);
  ~AVLTree();
  
  // Getter
  const Media* getRootValue() const;

  // Actions
  bool insert(Media*& val);
  
  bool retrieve(const Media& target, Media*& ret_val) const;
  
  void displayByLine() const;

  // Operator Overloads
  //AVLTree& operator = (const AVLTree& rval); 

  //bool operator == (const AVLTree& rval) const;

 protected: 

  class TreeNode {

  public: 

   // Constructors - Destructor
   TreeNode();
   TreeNode(Media& val);

   //~TreeNode();

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
  TreeNode* insertHelper(TreeNode*& currNode, Media*& val); 
  bool retrieveHelper(TreeNode* currNode, const Media& target, Media*& ret_val) const;

  void clearHelper(TreeNode*& delete_node);

  //bool equalityHelper(const TreeNode* lval_curr, const TreeNode* rval_curr) const;

  void displayByLineHelper(TreeNode* currNode) const;

  // Member Functions
  void makeRotation(const int bf, TreeNode*& curNode, Media*& val);
  void clear();

  void leftLeftRotation(TreeNode*& U);
  void rightRightRotation(TreeNode*& U);

  void rightLeftRotation(TreeNode*& U);
  void leftRightRotation(TreeNode*& U);

  // Member Data
  TreeNode* root;

  int nodeCount;
};

#endif