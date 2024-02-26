#include "AVLTree.h" 

// TreeNode
AVLTree::TreeNode::TreeNode() : key(0), value(nullptr), left(nullptr), right(nullptr), height(0) {};

AVLTree::TreeNode::TreeNode(int key, int val): key(key), value(new int(val)), left(nullptr), right(nullptr), height(0) {};

AVLTree::TreeNode::TreeNode(int key, int* val) : key(key), value(new int(*value)), left(nullptr), right(nullptr), height(0) {};

AVLTree::TreeNode::~TreeNode() {

    delete this->value;
    this->value = nullptr;
}

// Getters - Setters
int AVLTree::TreeNode::get_height() const {

    // Gives Warnings
    return (this == nullptr) ? 0 : this->height; 
}

int AVLTree::TreeNode::get_balance_factor() const {

    // Gives warning
    return (this == nullptr) ? 0 : this->left->get_height() - this->right->get_height();
}

void AVLTree::TreeNode::set_height(int new_height) {

    this->height = new_height;
}

// Actions
void AVLTree::TreeNode::updateHeight() {

    this->height = 1 + max(this->left->get_height(), this->right->get_height());
}

// AVLTree 
// Constructors - Destructor
// template <class T>
AVLTree::AVLTree() : root(nullptr), nodeCount(0) {}; // DONE

//template <class T>
AVLTree::AVLTree(const AVLTree& rval) { // Questioning Nessecity

    return;
}

//template <class T>
AVLTree::~AVLTree() { // DONE

    this->clear();
}

// Getters 

// Actions
//template <class T>
bool AVLTree::insert(int key, int val) { // DONE

    const int starting_node_count = this->nodeCount;

    this->root = insertHelper(this->root, key, val);

    return !(starting_node_count == this->nodeCount);
}

//template <class T>
AVLTree::TreeNode* AVLTree::insertHelper(TreeNode* currNode, int key, int val) { // TEMPLATIZE, REFACTOR

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
    
    currNode->updateHeight();

    const int balanace_factor = currNode->get_balance_factor();

    switch (currNode->get_balance_factor()) {

        case 0:
        case -1:
        case 1:
        break;

        default: 

        makeRotation(balanace_factor, key, currNode);
    }
    
    return currNode;
}

void AVLTree::makeRotation(const int bf, const int key, TreeNode*& curr) {

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

//template<class T>
bool AVLTree::retrieve(int key, int& ret_val) const { // TEMPLATIZE

    if (this->root == nullptr) {

        return false;
    }

    return retrieveHelper(this->root, key, ret_val);
}

bool AVLTree::retrieveHelper(TreeNode* currNode, int target_key, int& ret_val) const { // TEMPLATIZE

    // Base Cases 
    if (currNode == nullptr) { // Target not in the list

        return false;
    } else if (target_key == currNode->key) { 

        ret_val = *currNode->value;

        return true;
    } else if (target_key < currNode->key) { 

        return retrieveHelper(currNode->left, target_key, ret_val); 
    } else {

        return retrieveHelper(currNode->right, target_key, ret_val);
    }
}

//template<class T>
void AVLTree::leftLeftRotation(TreeNode*& unbalanced) { // DONE

    TreeNode* lhs = unbalanced->left;
    unbalanced->left = lhs->right;
    lhs->right = unbalanced;
    unbalanced = lhs;

    unbalanced->right->updateHeight();
    unbalanced->updateHeight();
}
  
//template<class T>
void AVLTree::rightRightRotation(TreeNode*& unbalanced) { // DONE

    TreeNode* rhs = unbalanced->right;
    unbalanced->right = rhs->left;
    rhs->left = unbalanced;
    unbalanced = rhs;

    unbalanced->left->updateHeight();
    unbalanced->updateHeight();
}

//template<class T>
void AVLTree::rightLeftRotation(TreeNode*& unbalanced) { // DONE

    leftLeftRotation(unbalanced->right);
    
    rightRightRotation(unbalanced);
}

//template<class T>
void AVLTree::leftRightRotation(TreeNode*& unbalanced) { // DONE

    rightRightRotation(unbalanced->left);
    
    leftLeftRotation(unbalanced);
}

void AVLTree::clear() { // DONE

    if (this->root == nullptr) { 

        return;
    }

    clearHelper(this->root);
}

void AVLTree::clearHelper(TreeNode*& delete_node) { // DONE

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

void AVLTree::displayTree() const { // Checks other function correctness

    int width_value = 5;
    
    cout << setfill(' ') << setw(width_value) << "Root: ";
    
    /*if (this->isEmpty()) { // Gaurd clause, empty tree

        return;
    }*/

    cout << *this->root->value << endl;

    displayTreeHelper(this->root, width_value += 5);
}

void AVLTree::displayTreeHelper(TreeNode* node, int width_value) const {

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

