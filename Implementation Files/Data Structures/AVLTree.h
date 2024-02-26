#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
class AVLTree {

 public: 
  
  // Constructors - Destructor
  AVLTree();
  //AVLTree(const AVLTree& rval);

  ~AVLTree();
  
  // Actions
  bool insert(int key, T* val);
  bool retrieve(int key, T*& ret_val) const; 

  void displayTree() const;

 protected: 

  // Memeber Data
  struct TreeNode {
    public: 
     
     // Constructors - Destructor
     TreeNode() : key(0), value(nullptr), left(nullptr), right(nullptr), height(0) {};
     TreeNode(int key, T val) : key(key), value(new T(val)), left(nullptr), right(nullptr), height(0) {};;
     TreeNode(int key, T* val) : key(key), value(new T(*val)), left(nullptr), right(nullptr), height(0) {};

     int key;
     int height;
     T* value;

     TreeNode* left;
     TreeNode* right;
  };

 private:
  
  // Member Functions
  void makeRotation(const int bf, const int key, TreeNode*& curNode);
  void clear();

  void leftLeftRotation(TreeNode*& U);
  void rightRightRotation(TreeNode*& U);

  void rightLeftRotation(TreeNode*& U);
  void leftRightRotation(TreeNode*& U);

  int get_height(TreeNode* curr) const;
  int get_balance_factor(TreeNode* curr) const;

  void set_height(TreeNode*& curr, int new_height);
  
  void updateHeight(TreeNode*& curr);

  // Helper Functions
  TreeNode* insertHelper(TreeNode* currNode, int key, T* val); 
  bool retrieveHelper(TreeNode* currNode, int target_key, T*& ret_val) const;

  void clearHelper(TreeNode*& delete_node);

  // Display 
  void displayTreeHelper(TreeNode* currNode, int width_value) const;

  // Member Data
  TreeNode* root;

  int nodeCount;
};

// Constructors - Destructor
template <typename T>
AVLTree<T>::AVLTree() : root(nullptr), nodeCount(0) {}; // DONE

template <typename T>
AVLTree<T>::~AVLTree() { // DONE

    this->clear();
}

// Getters 

// Actions
template <class T>
bool AVLTree<T>::insert(int key, T* val) { // DONE

    const int starting_node_count = this->nodeCount;

    this->root = insertHelper(this->root, key, val);

    return !(starting_node_count == this->nodeCount);
}

template <class T>
typename AVLTree<T>::TreeNode* AVLTree<T>::insertHelper(TreeNode* currNode, int key, T* val) { // DONE

    if (currNode == nullptr) {

        currNode = new TreeNode(key, val);

        ++this->nodeCount;
    } else if (key == currNode->key) { // Make no changes to the current tree

        return currNode;
    } else if (key < currNode->key) { 

        currNode->left = insertHelper(currNode->left, key, val);

    } else { // Go right

        currNode->right = insertHelper(currNode->right, key, val);

    }
    
    updateHeight(currNode);

    const int balanace_factor = get_balance_factor(currNode);

    switch (balanace_factor) {

        case 0:
        case -1:
        case 1:
        break;

        default: 

        makeRotation(balanace_factor, key, currNode);
    }
    
    return currNode;
}

template< class T>
void AVLTree<T>::makeRotation(const int bf, const int key, TreeNode*& curr) { // DONE

    if (bf > 1 && key < curr->left->key)
        
        leftLeftRotation(curr);
        
    if (bf < -1 && key > curr->right->key)
            
        rightRightRotation(curr);
        
    if (bf > 1 && key > curr->left->key) {

        leftRightRotation(curr);
    }
    
    if (bf < -1 && key < curr->right->key) {

        rightLeftRotation(curr);
    }
}

template<class T>
bool AVLTree<T>::retrieve(int key, T*& ret_val) const { // DONE

    if (this->root == nullptr) {

        return false;
    }

    return retrieveHelper(this->root, key, ret_val);
}

template<class T>
bool AVLTree<T>::retrieveHelper(TreeNode* currNode, int target_key, T*& ret_val) const { // DONE

    // Base Cases 
    if (currNode == nullptr) { // Target not in the list

        return false;
    } else if (target_key == currNode->key) { 

        ret_val = currNode->value;

        return true;
    } else if (target_key < currNode->key) { 

        return retrieveHelper(currNode->left, target_key, ret_val); 
    } else {

        return retrieveHelper(currNode->right, target_key, ret_val);
    }
}

template<class T>
void AVLTree<T>::leftLeftRotation(TreeNode*& unbalanced) { // DONE

    TreeNode* lhs = unbalanced->left;
    unbalanced->left = lhs->right;
    lhs->right = unbalanced;
    unbalanced = lhs;

    updateHeight(unbalanced->right);
    updateHeight(unbalanced);
}
  
template<class T>
void AVLTree<T>::rightRightRotation(TreeNode*& unbalanced) { // DONE

    TreeNode* rhs = unbalanced->right;
    unbalanced->right = rhs->left;
    rhs->left = unbalanced;
    unbalanced = rhs;

    updateHeight(unbalanced->left);
    updateHeight(unbalanced);
}

template<class T>
void AVLTree<T>::rightLeftRotation(TreeNode*& unbalanced) { // DONE

    leftLeftRotation(unbalanced->right);
    
    rightRightRotation(unbalanced);
}

template<class T>
void AVLTree<T>::leftRightRotation(TreeNode*& unbalanced) { // DONE

    rightRightRotation(unbalanced->left);
    
    leftLeftRotation(unbalanced);
}

template<class T>
void AVLTree<T>::clear() { // DONE

    if (this->root == nullptr) { 

        return;
    }

    clearHelper(this->root);
}

template<class T>
void AVLTree<T>::clearHelper(TreeNode*& delete_node) { // DONE

    if (delete_node == nullptr) {

        return;
    }

    clearHelper(delete_node->left); 

    clearHelper(delete_node->right); 

    delete_node->~TreeNode(); // ??
    delete delete_node;
    delete_node = nullptr;

    --this->nodeCount;
}

template<class T>
int AVLTree<T>::get_height(TreeNode* curr) const { // DONE

    return (curr == nullptr) ? 0 : curr->height; 
}

template<class T>
int AVLTree<T>::get_balance_factor(TreeNode* curr) const { // DONE

    return (curr == nullptr) ? 0 : get_height(curr) - get_height(curr);
}

template<class T>
void AVLTree<T>::set_height(TreeNode*& curr, int new_height) { // DONE

    curr->height = new_height;
}

template<class T>
void AVLTree<T>::updateHeight(TreeNode*& curr) { // DONE

    curr->height = 1 + max(get_height(curr->left), get_height(curr->right));
}

// Checks other functions correctness
template<class T>
void AVLTree<T>::displayTree() const {

    int width_value = 5;
    
    cout << setfill(' ') << setw(width_value) << "Root: ";

    cout << *this->root->value << endl;

    displayTreeHelper(this->root, width_value += 5);
}

template<class T>
void AVLTree<T>::displayTreeHelper(TreeNode* node, int width_value) const { 

    // Base Case
    if (node == nullptr) {

        return;
    }

    if (node->left != nullptr) {

        cout << setfill(' ') << setw(width_value) << "L---" << *node->left->value << endl;
        
        int width_copy = width_value + 5;

        displayTreeHelper(node->left, width_copy);
    }

    if (node->right != nullptr) {

        cout << setfill(' ') << setw(width_value) << "R---" << *node->right->value << endl;
        
        int width_copy = width_value + 5;

        displayTreeHelper(node->right, width_copy);
    }
}

#endif