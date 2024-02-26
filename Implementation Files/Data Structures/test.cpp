#include <iomanip>

#include "AVLTree.h"

using namespace std;

int main() {
    
    const int arraySize = 12;
    const int testArr[arraySize] = {3333, 8888, 4444, 9999, 6666, 7777, 1111, 
                                    1000, 9000, 8000, 5000, 2000};
 
    AVLTree tree;
    int testNum = 10;

    for (int i = 0; i < arraySize; i++) {

        tree.insert(testArr[i], testArr[i]);
    }

    tree.displayTree();

    return 0;
}