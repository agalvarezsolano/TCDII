#include <iostream>
#include "DataStructures/LinkedList.cpp"
#include "Sorts/SortAlgorithms.cpp"
#import <ctime>


using namespace std;

int main() {
    LinkedList<int> *list = new LinkedList<int>();


    list->printList();
    unsigned t0 = clock();

    //SortAlgorithms<int>::mergeSort(list);


    unsigned t1 = clock();

    list->printList();

    double time = double(t1- t0)/1000;

    cout << time<< endl;

    return 0;
}