#include "AVLTree.h" 

// Constructors - Destructor
// template <class T>
AVLTree::AVLTree() { // DONE

    this->root = nullptr;

    this->nodeCount = 0;
}

////template <class T>
AVLTree::AVLTree(const AVLTree& rval) { // Questioning Nessecity

    return;
}

//template <class T>
AVLTree::~AVLTree() { // DONE

    this->clear();
}

// Getters 
//template<class T>
int AVLTree::get_height(TreeNode* currNode) {

    return (currNode == nullptr) ? 0 : currNode->height;
}

//template<class T>
int AVLTree::get_balance_factor(TreeNode* currNode) {

    return (currNode == nullptr) ? 0 : currNode->left->height - currNode->right->height;
}

// Actions
//template <class T>
bool AVLTree::insert(int key, int val) {

    const int starting_node_count = this->nodeCount;

    this->root = insertHelper(this->root, key, val);

    return !(starting_node_count == this->nodeCount);
}

//template <class T>
AVLTree::TreeNode* AVLTree::insertHelper(TreeNode* currNode, int key, int val) {

    if (currNode == nullptr) {

        currNode = new TreeNode(key, val);

        ++this->nodeCount;

        return currNode;
    } else if (key == currNode->key) { // Make no changes to the current tree

        return currNode;
    } else if (key < currNode->key) { 

        currNode->left = insertHelper(currNode->left, key, val);
    } else { // Go right

        currNode->right = insertHelper(currNode->right, key, val);
    }

    return currNode;
}

//template<class T>
bool AVLTree::retrieve(int key, int& ret_val) const {

    if (this->root == nullptr) {

        return false;
    }

    return retrieveHelper(this->root, key, ret_val);
}

bool AVLTree::retrieveHelper(TreeNode* currNode, int target_key, int& ret_val) const {

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

//template<class T>
AVLTree::TreeNode* AVLTree::leftLeftRotation(TreeNode*& U) {

    return nullptr;
}
  
//template<class T>
AVLTree::TreeNode* AVLTree::rightRightRotation(TreeNode*& U) {

    return nullptr;
}

//template<class T>
AVLTree::TreeNode* AVLTree::rightLeftRotation(TreeNode*& U) {

    return nullptr;
}

//template<class T>
AVLTree::TreeNode* AVLTree::leftRightRotation(TreeNode*& U) {

    return nullptr;
}

void AVLTree::clear() {

    if (this->root == nullptr) { 

        return;
    }

    clearHelper(this->root);
}

void AVLTree::clearHelper(TreeNode*& delete_node) {

    if (delete_node == nullptr) {

        return;
    }

    clearHelper(delete_node->left); 

    clearHelper(delete_node->right); 

    delete delete_node;
    delete_node = nullptr;

    --this->nodeCount;
}