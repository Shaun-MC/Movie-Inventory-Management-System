#include "AVLTree.h"

// TreeNode

// Constructors - Destructor
AVLTree::TreeNode::TreeNode() : value(nullptr), left(nullptr), right(nullptr), height(0) {}

AVLTree::TreeNode::TreeNode(Media& val) : value(&val), left(nullptr), right(nullptr), height(0) {};

// Getters - Setter
int AVLTree::TreeNode::getHeight() const {

    const TreeNode* ptr = this;

    return (ptr == nullptr) ? 0 : this->height; 
}

int AVLTree::TreeNode::getBalanceFactor() const {

    const TreeNode* ptr = this;

    return (ptr == nullptr) ? 0 : this->left->getHeight() - this->right->getHeight(); 
}

void AVLTree::TreeNode::setHeight(const int amount) {

    this->height = amount;
}

// Actions
void AVLTree::TreeNode::UpdateHeight() {

    this->height = 1 + max(this->left->getHeight(), this->right->getHeight());
}

// AVLTree
// Constructors - Destructor
AVLTree::AVLTree() : root(nullptr), nodeCount(0) {}; 

AVLTree::~AVLTree() { // DONE - Gets called with garbage sometimes

    this->clear();
}

/*AVLTree::AVLTree(const AVLTree& rval) : root(nullptr), nodeCount(0) {

    *this = rval;
}

// Operator Overloads
/AVLTree& AVLTree::operator = (const AVLTree& rval) {

    if (*this == rval); // Exact same trees

    else if (rval.getNodeCount() == 0) {

        this->clear();
    } else {

        this->clear();

        // ...
    }

    return *this;
}

bool AVLTree::operator == (const AVLTree& rval) const {

    // Execution order doesn't matter in this case
    // Could condence into ternary operator, less readable
    if ((this == &rval || (this->root == nullptr && rval.root == nullptr))) {

        return true;
    } else {

        return this->equalityHelper(this->root, rval.root); 
    }
}

bool AVLTree::equalityHelper(const TreeNode* lval_curr, const TreeNode* rval_curr) const {

    // Base Cases
    if (lval_curr == nullptr && rval_curr == nullptr) {

        return true;
    } else if (lval_curr == nullptr || rval_curr == nullptr) {

        return false;
    }

    if (*lval_curr->value == *rval_curr->value) {


    }
}*/

// Getters
const Media* AVLTree::getRootValue() const {

    return this->root->value;
}

int AVLTree::getNodeCount() const {

    return this->nodeCount;
}

// Actions
bool AVLTree::insert(Media*& val) { // DONE

    const int starting_node_count = this->nodeCount;

    this->root = insertHelper(this->root, val);

    return !(starting_node_count == this->nodeCount);
}

AVLTree::TreeNode* AVLTree::insertHelper(TreeNode*& currNode, Media*& val) { // DONE

    if (currNode == nullptr) {

        currNode = new TreeNode();
        currNode->value = val; // Reference cannot be deleted anywhere except in the AVLTree Destructor

        ++this->nodeCount;
    } else if (*val == *currNode->value) { 
        
        // Make no changes to the current tree 
        // Merge the Media objects if that Classic Movie is already in the system
            // Destory the passed in Media object 

        Classic* test = dynamic_cast<Classic*>(val); // Use static_cast??

        if (test != nullptr) {

            Classic* temp = dynamic_cast<Classic*>(currNode->value);

            temp->Merge(test);

            delete val;
            val = nullptr;
        }

        return currNode;

    } else if (*val < *currNode->value) { 

        currNode->left = insertHelper(currNode->left, val);

    } else { // Go right

        currNode->right = insertHelper(currNode->right, val);
    }
    
    currNode->UpdateHeight();

    const int balanace_factor = currNode->getBalanceFactor();

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

void AVLTree::makeRotation(const int bf, TreeNode*& curr, Media*& val) { // DONE

    if (bf > 1 && *val < *curr->left->value) {

        leftLeftRotation(curr);
    } else if (bf < -1 && *val > *curr->right->value) {

        rightRightRotation(curr);
    } else if (bf > 1 && *val > *curr->left->value) {

        leftRightRotation(curr);
    } else if (bf < -1 && *val < *curr->right->value) {

        rightLeftRotation(curr);
    }
}

bool AVLTree::retrieve(const Media& target, Media*& ret_val) const { // UNTESTED

    if (this->root == nullptr) {

        return false;
    }

    return retrieveHelper(this->root, target, ret_val);
}

// Assume that T has an equality and less than operator
bool AVLTree::retrieveHelper(TreeNode* currNode, const Media& target, Media*& ret_val) const { // UNTESTED

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

void AVLTree::leftLeftRotation(TreeNode*& unbalanced) { // DONE

    TreeNode* lhs = unbalanced->left;
    unbalanced->left = lhs->right;
    lhs->right = unbalanced;
    unbalanced = lhs;

    unbalanced->right->UpdateHeight();
    unbalanced->UpdateHeight();
}
  
void AVLTree::rightRightRotation(TreeNode*& unbalanced) { // DONE

    TreeNode* rhs = unbalanced->right;
    unbalanced->right = rhs->left;
    rhs->left = unbalanced;
    unbalanced = rhs;

    unbalanced->left->UpdateHeight();
    unbalanced->UpdateHeight();
}

void AVLTree::rightLeftRotation(TreeNode*& unbalanced) { // DONE

    leftLeftRotation(unbalanced->right);
    
    rightRightRotation(unbalanced);
}

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

    delete delete_node->value;
    delete delete_node;
    delete_node = nullptr;

    --this->nodeCount;
}

void AVLTree::displayByLine() const {

    this->displayByLineHelper(this->root);

    cout << endl;
}

void AVLTree::displayByLineHelper(TreeNode* currNode) const {

    if (currNode == nullptr) {

        return;
    }

    displayByLineHelper(currNode->left);

    cout << *currNode->value << endl;

    displayByLineHelper(currNode->right);
}