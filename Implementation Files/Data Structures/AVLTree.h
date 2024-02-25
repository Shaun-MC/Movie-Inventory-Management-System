#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

using namespace std;

class AVLTree {

 public: 

  // Memeber Data
  struct TreeNode {

    int key;
    int value; // change to a pointer eventually

    TreeNode* left;
    TreeNode* right;

    int height;

    TreeNode(): key(0), value(0), left(nullptr), right(nullptr), height(0) {};
    TreeNode(int key, int val): key(key), value(val), left(nullptr), right(nullptr), height(1) {};

    // Get balance factor
  };
  
  // Constructors - Destructor
  AVLTree();
  AVLTree(const AVLTree& rval);

  ~AVLTree();

  // Getter
  int get_height(TreeNode* currNode);
  int get_balance_factor(TreeNode* currNode);
  
  // Actions
  bool insert(int key, int val);
  bool retrieve(int key, int val); 

 private:
  
  // Member Functions
  void clear();

  TreeNode* leftLeftRotation(TreeNode*& U);
  TreeNode* rightRightRotation(TreeNode*& U);

  TreeNode* rightLeftRotation(TreeNode*& U);
  TreeNode* leftRightRotation(TreeNode*& U);

  // Helper Functions
  TreeNode* insertHelper(TreeNode* currNode, int key, int val); 
  
  void clearHelper(TreeNode*& delete_node);

  // Member Data
  TreeNode* root;

  int nodeCount;
};

#endif