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
  bool Insert(Media*& val);
  
  bool Retrieve(const Media& target, Media*& ret_val) const;
  
  void DisplayByLine() const;

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
  TreeNode* InsertHelper(TreeNode*& currNode, Media*& val); 
  bool RetrieveHelper(TreeNode* currNode, const Media& target, Media*& ret_val) const;

  void ClearHelper(TreeNode*& delete_node);

  //bool equalityHelper(const TreeNode* lval_curr, const TreeNode* rval_curr) const;

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