#include <iostream>
#include "DataStructures/BinarySearchTree.h"
#include "DataStructures/AVLTree.h"
#include "DataStructures/LinkedList.h"
#include "Sorts/SortAlgorithms.h"
#import <ctime>


using namespace std;

int main() {
    //LinkedList<int> *list = new LinkedList<int>();
    //BinarySearchTree<int> *tree = new BinarySearchTree<int>();
    //AVLTree<int> *tree = new AVLTree<int>();

    //list->printList();
    unsigned t0 = clock();


    /*
    tree->insert(10);
    tree->insert(78);
    tree->insert(64);
    tree->insert(24);
    tree->insert(12);

*/

    //SortAlgorithms<int>::mergeSort(list);

    unsigned t1 = clock();

    //list->printList();

    double time = double(t1- t0)/1000;

    cout << time<< endl;

    return 0;
}