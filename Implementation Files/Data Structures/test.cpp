#include <iomanip>

#include "AVLTree.h"
#include "HashTable.h"

using namespace std;

int main() {
    
    /*int k3333 = 3333;
    int* p1 = &k3333;

    int k8888 = 8888;
    int* p2 = &k8888;

    int k4444 = 4444;
    int* p3 = &k4444;

    int k9999 = 9999;
    int* p4 = &k9999;

    int k6666 = 6666;
    int* p5 = &k6666;

    int k7777 = 7777;
    int* p6 = &k7777;

    int k1111 = 1111;
    int* p7 = &k1111;

    int k1000 = 1000;
    int* p8 = &k1000;

    int k9000 = 9000;
    int* p9 = &k9000;

    int k8000 = 8000;
    int* p10 = &k8000;

    int k5000 = 5000;
    int* p11 = &k5000;

    int k2000 = 2000;
    int* p12 = &k2000;

    const int arraySize = 12;
    int testArr[] = {3333, 8888, 4444, 9999, 6666, 7777, 1111, 1000, 9000, 8000, 5000, 2000};
    int* arrPtr = &testArr[0];
    
    int* ptrArr[arraySize] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12};

    AVLTree<int> tree;
    int testNum = 10;

    for (int i = 0; i < arraySize; i++) {

        tree.insert(testArr[i], ptrArr[i]);
    }

    tree.displayTree();

    int* test_ptr = nullptr;
    tree.retrieve(3333, test_ptr);

    cout << *test_ptr;*/

    HashTable<int, int> test;
    int* ret = nullptr;

    test.insertKeyValue(100, 11);

    test.retireveValue(100, ret);

    return 0;
}