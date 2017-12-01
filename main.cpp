#include <iostream>
#include "DataStructures/LinkedList.cpp"
#include "Sorts/SortAlgorithms.cpp"
#include <ctime>

using namespace std;

int main() {
    LinkedList<int> *list = new LinkedList<int>();
   // list->insertAtEnd(1);
    list->insertAtEnd(3);
    list->insertAtEnd(8);
    list->insertAtEnd(4);
    list->insertAtEnd(5);
    list->insertAtEnd(2);
/*
    list->insertAtEnd(5);
    list->insertAtEnd(7);
    list->insertAtEnd(9);
    list->insertAtEnd(10);
    list->insertAtEnd(6);

    list->insertAtEnd(3);
    list->insertAtEnd(8);
    list->insertAtEnd(4);
    list->insertAtEnd(5);
    list->insertAtEnd(2);

    list->insertAtEnd(5);
    list->insertAtEnd(7);
    list->insertAtEnd(9);
    list->insertAtEnd(10);
    list->insertAtEnd(6);

    list->insertAtEnd(3);
    list->insertAtEnd(8);
    list->insertAtEnd(4);
    list->insertAtEnd(5);
    list->insertAtEnd(2);

    list->insertAtEnd(5);
    list->insertAtEnd(7);
    list->insertAtEnd(9);
    list->insertAtEnd(10);
    list->insertAtEnd(6);


    list->insertAtEnd(3);
    list->insertAtEnd(8);
    list->insertAtEnd(4);
    list->insertAtEnd(5);
    list->insertAtEnd(2);
*/
    list->printList();

    unsigned t0 = clock();
    SortAlgorithms<int>::bubbleSort(list);
    unsigned t1 = clock();

    list->printList();

    int time = int(t1- t0);
    cout << time << endl;

    return 0;
}