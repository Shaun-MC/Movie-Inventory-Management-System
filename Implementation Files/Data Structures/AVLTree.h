#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <iomanip>

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
    TreeNode(int key, int val): key(key), value(val), left(nullptr), right(nullptr), height(0) {};
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
  bool retrieve(int key, int& ret_val) const; 

  //void displayTree() const;

 private:
  
  // Member Functions
  void clear();

  void leftLeftRotation(TreeNode*& U);
  void rightRightRotation(TreeNode*& U);

  void rightLeftRotation(TreeNode*& U);
  void leftRightRotation(TreeNode*& U);

  // Helper Functions
  TreeNode* insertHelper(TreeNode* currNode, int key, int val); 
  bool retrieveHelper(TreeNode* currNode, int target_key, int& ret_val) const;

  void clearHelper(TreeNode*& delete_node);

  // Display Debugging
  //void displayTreeHelper(TreeNode* currNode, int width_value) const;

  // Member Data
  TreeNode* root;

  int nodeCount;
};

#endif