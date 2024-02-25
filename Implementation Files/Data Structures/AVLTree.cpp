#include "AVLTree.h" 

// Constructors - Destructor
////template <class T>
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

    // Gaurd clase, empty tree
    if (this->root == nullptr) {

        TreeNode* insertNode = new TreeNode(key, val); // Deleted in Destructor

        this->root = insertNode;
        ++this->nodeCount;

        return true;
    }

    const int prevCount = this->nodeCount;

    this->root = insertHelper(this->root, key, val);

    // If a new node was inserted, then nodeCount will be incremented 
    return !(prevCount == this->nodeCount);    
}

//template <class T>
AVLTree::TreeNode* AVLTree::insertHelper(TreeNode* currNode, int key, int val) {

    if (currNode == nullptr) {

        return new TreeNode(key, val); 
    } else if (key == currNode->key) { // FIGURE IT OUT


    } else if (key < currNode->key) { 

        currNode->left = insertHelper(currNode->left, key, val);
    } else { 

        currNode->left = insertHelper(currNode->left, key, val);
    }

    currNode->height = 1 + std::max(currNode->left->height, currNode->right->height);

    const int balance_factor = get_balance_factor(currNode);

    if (balance_factor < -1 && key > currNode->right->key) { 

        return leftLeftRotation(currNode);
    } 

    if (balance_factor > 1 && key < currNode->left->key) { 

        return rightRightRotation(currNode);
    }

    if (balance_factor < -1 && key < currNode->right->key) {

        return leftRightRotation(currNode);
    }

    if (balance_factor > 1 && key > currNode->left->key) { 

        return rightLeftRotation(currNode);
    }

    return currNode; 
}

//template<class T>
bool AVLTree::retrieve(int key, int val) {

    return true;
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

    if (this->root == nullptr) { // Assumption: empty list

        return;
    }

    clearHelper(this->root);

    delete this->root; // Unessecary
    this->root = nullptr;
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



