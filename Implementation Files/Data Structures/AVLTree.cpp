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
int AVLTree::get_height(TreeNode* currNode) { // DONE

    return (currNode == nullptr) ? 0 : currNode->height;
}

//template<class T>
int AVLTree::get_balance_factor(TreeNode* currNode) { // DONE

    return (currNode == nullptr) ? 0 : get_height(currNode->left) - get_height(currNode->right);
}

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
    
    currNode->height = 1 + max(get_height(currNode->left), get_height(currNode->right));

    const int balance_factor = get_balance_factor(currNode);

    if (balance_factor > 1 && key < currNode->left->key)
        
        leftLeftRotation(currNode);
        
    if (balance_factor < -1 && key > currNode->right->key)
            
        rightRightRotation(currNode);
        
    if (balance_factor > 1 && key > currNode->left->key) {

        leftRightRotation(currNode);
    }
    
    if (balance_factor < -1 && key < currNode->right->key) {

        rightLeftRotation(currNode);
    }
    
    return currNode;
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

        ret_val = currNode->value;

        return true;
    } else if (target_key < currNode->key) { 

        return retrieveHelper(currNode->left, target_key, ret_val); 
    } else {

        return retrieveHelper(currNode->right, target_key, ret_val);
    }
}

//template<class T>
void AVLTree::leftLeftRotation(TreeNode*& unbalanced) { // REFACTOR

    // Execute Rotation
    TreeNode* lhs = unbalanced->left;
    
    unbalanced->left = lhs->right;
    
    lhs->right = unbalanced;
    
    unbalanced = lhs;

    // Update Node Heights
    unbalanced->right->height = 1 + max(get_height(unbalanced->right->left), get_height(unbalanced->right->right));
    unbalanced->height = 1 + max(get_height(unbalanced->left), get_height(unbalanced->right));
}
  
//template<class T>
void AVLTree::rightRightRotation(TreeNode*& unbalanced) { // REFACTOR

    TreeNode* rhs = unbalanced->right;
    
    unbalanced->right = rhs->left;
    
    rhs->left = unbalanced;
    
    unbalanced = rhs;

    unbalanced->left->height = 1 + max(get_height(unbalanced->left->left), get_height(unbalanced->left->right));
    unbalanced->height =  1 + max(get_height(unbalanced->left), get_height(unbalanced->right));
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

    delete delete_node;
    delete_node = nullptr;

    --this->nodeCount;
}

/*void AVLTree::displayTree() const { // Checks other function correctness

    int width_value = 5;
    
    cout << setfill(' ') << setw(width_value) << "Root: ";
    
    if (this->isEmpty()) { // Gaurd clause, empty tree

        return;
    }

    cout << this->root->value << endl;

    displayTreeHelper(this->root, width_value += 5);
}

void AVLTree::displayTreeHelper(TreeNode* node, int width_value) const {

    // Base Case
    if (node == nullptr) {

        return;
    }

    if (node->left != nullptr) {

        cout << setfill(' ') << setw(width_value) << "L---" << node->left->value << endl;
        
        int width_copy = width_value + 5;

        displayTreeHelper(node->left, width_copy);
    }

    if (node->right != nullptr) {

        cout << setfill(' ') << setw(width_value) << "R---" << node->right->value << endl;
        
        int width_copy = width_value + 5;

        displayTreeHelper(node->right, width_copy);
    }
}*/

