#ifndef AVLTREE_H
#define AVLTREE_H

template<class T>
class AVLTree<T> {

 public: 
  
  // Constructors - Destructor
  AVLTree();
  AVLTree(const AVLTree& rval);

  ~AVLTree();

  // Getters - Setters
  TreeNode* getRoot() const;
  void setRoot(int key, T& val);
  
  // Actions
  bool insert(int key, T& val);
  bool retrieve(int key, T& val); 
  bool keyExists(int key);

  // Memeber Data
  struct TreeNode {

    int key;
    Customer* value;

    TreeNode* left;
    TreeNode* right;

    int height;

    TreeNode(): key(0), value(nullptr), left(nullptr), right(nullptr), height(0) {};
    TreeNode(int key, T& val): key(key), value(cust), left(nullptr), right(nullptr), height(0) {};
  }

 protected:

 private:
  
  // Member Functions
  bool isLeaf();

  void clear();

  TreeNode* rightRightRotation(TreeNode*& U);
  TreeNode* leftLeftRotation(TreeNode*& U);

  TreeNode* rightLeftRotation(TreeNode*& U);
  TreeNode* leftRightRotation(TreeNode*& U);

  // Member Data
  TreeNode* root;
};

#endif