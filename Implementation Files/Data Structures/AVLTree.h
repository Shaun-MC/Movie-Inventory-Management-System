#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <iomanip>

using namespace std;

class AVLTree {

 public: 

  // Memeber Data
  class TreeNode {
    public: 
     
     // Constructors - Destructor
     TreeNode();
     TreeNode(int key, int val);
     TreeNode(int key, int* val);

     // Destructor
     ~TreeNode();

     // Getters - Setters
     int get_height() const;
     int get_balance_factor() const;

     void set_height(int new_height);

     // Actions
     void updateHeight();

     int key;
     int height;
     int* value;

     TreeNode* left;
     TreeNode* right;

     //TreeNode(): key(0), value(0), left(nullptr), right(nullptr), height(0) {};
     //TreeNode(int key, int val): key(key), value(val), left(nullptr), right(nullptr), height(0) {};
  };
  
  // Constructors - Destructor
  AVLTree();
  AVLTree(const AVLTree& rval);

  ~AVLTree();
  
  // Actions
  bool insert(int key, int val);
  bool retrieve(int key, int& ret_val) const; 

  void displayTree() const;

 private:
  
  // Member Functions
  void makeRotation(const int bf, const int key, TreeNode*& curNode);
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
  void displayTreeHelper(TreeNode* currNode, int width_value) const;

  // Member Data
  TreeNode* root;

  int nodeCount;
};

#endif