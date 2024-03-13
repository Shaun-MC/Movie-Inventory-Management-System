#include "AVLTree.h"

// -----------------------------------------------------------------------------------------------
// TreeNode
// -----------------------------------------------------------------------------------------------

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor - Destructor?
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AVLTree::TreeNode::TreeNode() : value(nullptr), left(nullptr), right(nullptr), height(0) {}

AVLTree::TreeNode::TreeNode(Media& val) : value(&val), left(nullptr), right(nullptr), height(0) {};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Getters - Setter
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AVLTree::TreeNode::UpdateHeight() {

    this->height = 1 + max(this->left->getHeight(), this->right->getHeight());
}

// -----------------------------------------------------------------------------------------------
// AVLTree
// -----------------------------------------------------------------------------------------------

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructors - Destructor
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AVLTree::AVLTree() : root(nullptr), nodeCount(0) {}; 

AVLTree::~AVLTree() { // DONE - Gets called with garbage sometimes

    this->Clear();
}

/*AVLTree::AVLTree(const AVLTree& rval) : root(nullptr), nodeCount(0) {

    *this = rval;
}

// Operator Overloads
/AVLTree& AVLTree::operator = (const AVLTree& rval) {

    if (*this == rval); // Exact same trees

    else if (rval.getNodeCount() == 0) {

        this->Clear();
    } else {

        this->Clear();

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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Getters
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Media* AVLTree::getRootValue() const {

    return (this->root == nullptr) ? nullptr : this->root->value;
}

int AVLTree::getNodeCount() const {

    return this->nodeCount;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool AVLTree::Insert(Media*& val) { // DONE

    const int starting_node_count = this->nodeCount;

    this->root = InsertHelper(this->root, val);

    return !(starting_node_count == this->nodeCount);
}

AVLTree::TreeNode* AVLTree::InsertHelper(TreeNode*& currNode, Media*& val) { // DONE

    if (currNode == nullptr) {

        currNode = new TreeNode();
        currNode->value = val; // Reference cannot be deleted anywhere except in the AVLTree Destructor

        ++this->nodeCount;
    } else if (*val == *currNode->value) { 
        
        // Make no changes to the current tree 
        // Merge the Media objects if that Classic Movie is already in the system
            // Destory the passed in Media object 

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

    } else { // Go right

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

bool AVLTree::Retrieve(const Media& target, Media*& ret_val) const { // UNTESTED

    if (this->root == nullptr) {

        return false;
    }

    return RetrieveHelper(this->root, target, ret_val);
}

bool AVLTree::RetrieveHelper(TreeNode* currNode, const Media& target, Media*& ret_val) const { // UNTESTED

    // Base Cases 
    if (currNode == nullptr) { // Target not in the list

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

void AVLTree::DisplayByLine() const {

    this->DisplayByLineHelper(this->root);

    cout << endl;
}

void AVLTree::DisplayByLineHelper(TreeNode* currNode) const {

    if (currNode == nullptr) {

        return;
    }

    DisplayByLineHelper(currNode->left);

    cout << *currNode->value << endl;

    DisplayByLineHelper(currNode->right);
}

void AVLTree::Clear() { // DONE

    if (this->root == nullptr) { 

        return;
    }

    ClearHelper(this->root);
}

void AVLTree::ClearHelper(TreeNode*& delete_node) { // DONE

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
void AVLTree::MakeRotation(const int bf, TreeNode*& curr, Media*& val) { // DONE

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

void AVLTree::LeftLeftRotation(TreeNode*& unbalanced) { // DONE

    TreeNode* lhs = unbalanced->left;
    unbalanced->left = lhs->right;
    lhs->right = unbalanced;
    unbalanced = lhs;

    unbalanced->right->UpdateHeight();
    unbalanced->UpdateHeight();
}
  
void AVLTree::RightRightRotation(TreeNode*& unbalanced) { // DONE

    TreeNode* rhs = unbalanced->right;
    unbalanced->right = rhs->left;
    rhs->left = unbalanced;
    unbalanced = rhs;

    unbalanced->left->UpdateHeight();
    unbalanced->UpdateHeight();
}

void AVLTree::RightLeftRotation(TreeNode*& unbalanced) { // DONE

    LeftLeftRotation(unbalanced->right);
    
    RightRightRotation(unbalanced);
}

void AVLTree::LeftRightRotation(TreeNode*& unbalanced) { // DONE

    RightRightRotation(unbalanced->left);
    
    LeftLeftRotation(unbalanced);
}