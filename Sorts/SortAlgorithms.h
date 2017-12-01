//
// Created by adrian on 31/11/17.
//

#ifndef SORTALGORITHMS_SORTALGORITHMS_H
#define SORTALGORITHMS_SORTALGORITHMS_H


#include "../DataStructures/LinkedList.h"

template <class T>
class SortAlgorithms {
public:
    static void bubbleSort(LinkedList<T> *list);

    static void selectionSort(LinkedList<T> *list);

    static void insertionSort(LinkedList<T> *list);

    static LinkedList<T>* mergeSort(LinkedList<T> *list);

    static void quickSort(LinkedList<T> *list);

private:
    static void quickSort(LinkedList<T> *list, int first, int last);
};


#endif //SORTALGORITHMS_SORTALGORITHMS_H
