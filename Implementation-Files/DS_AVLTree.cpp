#include "DS_AVLTree.h"

// -----------------------------------------------------------------------------------------------
// TreeNode
// -----------------------------------------------------------------------------------------------

// Constructor 
AVLTree::TreeNode::TreeNode() : value(nullptr), left(nullptr), right(nullptr), height(0) {}

// Constructor with Media value
AVLTree::TreeNode::TreeNode(Media& val) : value(&val), left(nullptr), right(nullptr), height(0) {};

// Get height of the node
int AVLTree::TreeNode::getHeight() const {

    const TreeNode* ptr = this;

    return (ptr == nullptr) ? 0 : this->height; 
}

// Get balance factor of the node
int AVLTree::TreeNode::getBalanceFactor() const {

    const TreeNode* ptr = this;

    return (ptr == nullptr) ? 0 : this->left->getHeight() - this->right->getHeight(); 
}

// Set height of the node
void AVLTree::TreeNode::setHeight(const int amount) {

    this->height = amount;
}

// Update height of the node
void AVLTree::TreeNode::UpdateHeight() {

    this->height = 1 + max(this->left->getHeight(), this->right->getHeight());
}

// -----------------------------------------------------------------------------------------------
// AVLTree
// -----------------------------------------------------------------------------------------------

// Default constructor
AVLTree::AVLTree() : root(nullptr), nodeCount(0) {}; 

// Destructor
AVLTree::~AVLTree() { 

    this->Clear();
}

// Get value of root node
Media* AVLTree::getRootValue() const {

    return (this->root == nullptr) ? nullptr : this->root->value;
}

// Get number of nodes in the tree
int AVLTree::getNodeCount() const {

    return this->nodeCount;
}

// Insert a node into the AVL tree
bool AVLTree::Insert(Media*& val) {

    const int starting_node_count = this->nodeCount;

    this->root = InsertHelper(this->root, val);

    return !(starting_node_count == this->nodeCount);
}

// Helper function to insert a node into the AVL tree
AVLTree::TreeNode* AVLTree::InsertHelper(TreeNode*& currNode, Media*& val) { 

    if (currNode == nullptr) {
        currNode = new TreeNode();
        currNode->value = val; 
        ++this->nodeCount;

    } else if (*val == *currNode->value) { 

        Classic* test = dynamic_cast<Classic*>(val); 

        if (test != nullptr) {
            Classic* temp = dynamic_cast<Classic*>(currNode->value);
            temp->Merge(test);
            delete val;
            val = nullptr;
        }

        return currNode;

    } else if (*val < *currNode->value) { 

        currNode->left = InsertHelper(currNode->left, val);

    } else { 

        currNode->right = InsertHelper(currNode->right, val);
    }
    
    currNode->UpdateHeight();

    const int balanace_factor = currNode->getBalanceFactor();

    switch (balanace_factor) {
        case 0:
        case -1:
        case 1:
        break;

        default: 
        MakeRotation(balanace_factor, currNode, val);
    }
    
    return currNode;
}

// Retrieve a node from the AVL tree
bool AVLTree::Retrieve(const Media& target, Media*& ret_val) const { 
    if (this->root == nullptr) {
        return false;
    }

    return RetrieveHelper(this->root, target, ret_val);
}

// Helper function to retrieve a node from the AVL tree
bool AVLTree::RetrieveHelper(TreeNode* currNode, const Media& target, Media*& ret_val) const { 

    if (currNode == nullptr) { 
        return false;

    } else if (target == *currNode->value) { 
        ret_val = currNode->value;
        return true;

    } else if (target < *currNode->value) { 
        return RetrieveHelper(currNode->left, target, ret_val); 

    } else {
        return RetrieveHelper(currNode->right, target, ret_val);
    }
}

// Display the AVL tree by line
void AVLTree::DisplayByLine() const {
    
    this->DisplayByLineHelper(this->root);
    cout << endl;
}

// Helper function to display the AVL tree by line
void AVLTree::DisplayByLineHelper(TreeNode* currNode) const {
    if (currNode == nullptr) {
        return;
    }

    DisplayByLineHelper(currNode->left);

    cout << *currNode->value << endl;

    DisplayByLineHelper(currNode->right);
}

// Clear the AVL tree
void AVLTree::Clear() { 
    if (this->root == nullptr) { 
        return;
    }

    ClearHelper(this->root);
}

// Helper function to clear the AVL tree
void AVLTree::ClearHelper(TreeNode*& delete_node) { 

    if (delete_node == nullptr) {
        return;
    }

    ClearHelper(delete_node->left); 
    ClearHelper(delete_node->right); 

    delete delete_node->value;
    delete delete_node;
    delete_node = nullptr;

    --this->nodeCount;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Make rotation to balance the AVL tree
void AVLTree::MakeRotation(const int bf, TreeNode*& curr, Media*& val) { 

    if (bf > 1 && *val < *curr->left->value) {

        LeftLeftRotation(curr);
    } else if (bf < -1 && *val > *curr->right->value) {

        RightRightRotation(curr);
    } else if (bf > 1 && *val > *curr->left->value) {

        LeftRightRotation(curr);
    } else if (bf < -1 && *val < *curr->right->value) {

        RightLeftRotation(curr);
    }
}

// Perform left-left rotation
void AVLTree::LeftLeftRotation(TreeNode*& unbalanced) { 
    TreeNode* lhs = unbalanced->left;
    unbalanced->left = lhs->right;
    lhs->right = unbalanced;
    unbalanced = lhs;

    unbalanced->right->UpdateHeight();
    unbalanced->UpdateHeight();
}

// Perform right-right rotation  
void AVLTree::RightRightRotation(TreeNode*& unbalanced) {
    TreeNode* rhs = unbalanced->right;
    unbalanced->right = rhs->left;
    rhs->left = unbalanced;
    unbalanced = rhs;

    unbalanced->left->UpdateHeight();
    unbalanced->UpdateHeight();
}

// Perform right-left rotation
void AVLTree::RightLeftRotation(TreeNode*& unbalanced) { 
    LeftLeftRotation(unbalanced->right);
    RightRightRotation(unbalanced);
}

// Perform left-right rotation
void AVLTree::LeftRightRotation(TreeNode*& unbalanced) { 
    RightRightRotation(unbalanced->left);
    LeftLeftRotation(unbalanced);
}