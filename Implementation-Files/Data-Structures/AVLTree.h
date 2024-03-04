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

  ~AVLTree();
  
  // Actions
  bool insert(T& val);
  bool retrieve(const T& target, T*& ret_val) const;
  void displayTree() const;

 protected: 

  // Memeber Data
  struct TreeNode {
    
    T* value;

    TreeNode* left;
    TreeNode* right;

    int height;

    TreeNode() : value(nullptr), left(nullptr), right(nullptr), height(0) {};
  };

 private:
  
  // Member Functions
  void makeRotation(const int bf, TreeNode*& curNode, const T& val);
  void clear();

  void leftLeftRotation(TreeNode*& U);
  void rightRightRotation(TreeNode*& U);

  void rightLeftRotation(TreeNode*& U);
  void leftRightRotation(TreeNode*& U);

  int getHeight(TreeNode* curr) const;
  int getBalanceFactor(TreeNode* curr) const;

  void setHeight(TreeNode*& curr, int newHeight);
  
  void updateHeight(TreeNode*& curr);

  // Helper Functions
  TreeNode* insertHelper(TreeNode*& currNode, T& val); 
  bool retrieveHelper(TreeNode* currNode, const T& target, T*& ret_val) const;

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
AVLTree<T>::~AVLTree() { // DONE - Gets called with garbage

    this->clear();
}

// Getters 

// Actions
template <class T>
bool AVLTree<T>::insert(T& val) { // DONE

    const int starting_node_count = this->nodeCount;

    this->root = insertHelper(this->root, val);

    return !(starting_node_count == this->nodeCount);
}

// Assumes that type T has an eqaulity and less than operator
template <class T>
typename AVLTree<T>::TreeNode* AVLTree<T>::insertHelper(TreeNode*& currNode, T& val) { // DONE

    if (currNode == nullptr) {

        currNode = new TreeNode();
        currNode->value = &val; // Cannot be deleted anywhere except in the AVLTree Destructor

        ++this->nodeCount;
    } else if (val == *currNode->value) { // Make no changes to the current tree

        return currNode;
    } else if (val < *currNode->value) { 

        currNode->left = insertHelper(currNode->left, val);

    } else { // Go right

        currNode->right = insertHelper(currNode->right, val);
    }
    
    updateHeight(currNode);

    const int balanace_factor = getBalanceFactor(currNode);

    switch (balanace_factor) {

        case 0:
        case -1:
        case 1:
        break;

        default: 

        makeRotation(balanace_factor, currNode, val);
    }
    
    return currNode;
}

// Assumes that type T has a less than and greater than operator
template< class T>
void AVLTree<T>::makeRotation(const int bf, TreeNode*& curr, const T& val) { // DONE

    if (bf > 1 && val < *curr->left->value) {

        leftLeftRotation(curr);
    } else if (bf < -1 && val > *curr->right->value) {

        rightRightRotation(curr);
    } else if (bf > 1 && val > *curr->left->value) {

        leftRightRotation(curr);
    } else if (bf < -1 && val < *curr->right->value) {

        rightLeftRotation(curr);
    }
}

template<class T>
bool AVLTree<T>::retrieve(const T& target, T*& ret_val) const { // UNTESTED

    if (this->root == nullptr) {

        return false;
    }

    return retrieveHelper(this->root, target, ret_val);
}

// Assume that T has an equality and less than operator
template<class T>
bool AVLTree<T>::retrieveHelper(TreeNode* currNode, const T& target, T*& ret_val) const { // UNTESTED

    // Base Cases 
    if (currNode == nullptr) { // Target not in the list

        return false;
    } else if (target == *currNode->value) { 

        ret_val = currNode->value;

        return true;
    } else if (target < *currNode->value) { 

        return retrieveHelper(currNode->left, target, ret_val); 
    } else {

        return retrieveHelper(currNode->right, target, ret_val);
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

    delete delete_node->value;
    delete delete_node;
    delete_node = nullptr;

    --this->nodeCount;
}

template<class T>
int AVLTree<T>::getHeight(TreeNode* curr) const { // DONE

    return (curr == nullptr) ? 0 : curr->height; 
}

template<class T>
int AVLTree<T>::getBalanceFactor(TreeNode* curr) const { // DONE

    return (curr == nullptr) ? 0 : getHeight(curr->left) - getHeight(curr->right);
}

template<class T>
void AVLTree<T>::setHeight(TreeNode*& curr, int new_height) { // DONE

    curr->height = new_height;
}

template<class T>
void AVLTree<T>::updateHeight(TreeNode*& curr) { // DONE

    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
}

// Checks other functions correctness
template<class T>
void AVLTree<T>::displayTree() const { // DONE

    int width_value = 5;
    
    cout << setfill(' ') << setw(width_value) << "Root: ";

    cout << *this->root->value << endl;

    displayTreeHelper(this->root, width_value += 5);
}

template<class T>
void AVLTree<T>::displayTreeHelper(TreeNode* node, int width_value) const { // DONE 

    // Base Case
    if (node == nullptr) {

        return;
    }

    if (node->left != nullptr) {

        cout << setfill(' ') << setw(width_value) << "L---" << *node->left->value << endl;
        
        int width_copy = width_value + 5;

        displayTreeHelper(node->left, width_copy);
    }

    cout << endl;
    
    if (node->right != nullptr) {

        cout << setfill(' ') << setw(width_value) << "R---" << *node->right->value << endl;
        
        int width_copy = width_value + 5;

        displayTreeHelper(node->right, width_copy);
    }
}

#endif