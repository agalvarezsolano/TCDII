//
// Created by adrian on 31/11/17.
//

#include "SortAlgorithms.h"

template <class T>
void SortAlgorithms<T>::bubbleSort(LinkedList<T> *list) {
    for(int i = list->getSize()- 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(list->getElement(j)->getData() > list->getElement(j + 1)->getData()){
                Node<T> *node1 = list->getElement(j);
                Node<T> *node2 = list->getElement(j + 1);
                T temp = node1->getData();
                node1->setData(node2->getData());
                node2->setData(temp);
            }
        }
    }
}


template <class T>
void SortAlgorithms<T>::selectionSort(LinkedList<T> *list) {
    for(int i = 0; i < list->getSize() - 1; i++){


        int posMin = i;
        for (int x = i; x < list->getSize(); x++) {
            if (list->getElement(posMin)->getData() > list->getElement(x)->getData()) {
                posMin = x;
            }
        }
        Node<T> *node1 = list->getElement(i);
        Node<T> *node2 = list->getElement(posMin);
        T temp = node1->getData();
        node1->setData(node2->getData());
        node2->setData(temp);
    }
}

template <class T>
void SortAlgorithms<T>::insertionSort(LinkedList<T> *list) {
    for(int i = 1; i < list->getSize(); i++){
        Node<T> *aux = new Node<T>(list->getElement(i)->getData());

        for(int x = i - 1; x >= 0; x--){
            if(list->getElement(x)->getData() > aux->getData()){
                Node<T> *node1 = list->getElement(x + 1);
                Node<T> *node2 = list->getElement(x);
                node1->setData(node2->getData());
                node2->setData(aux->getData());
            }
        }
    }
}


template <class T>
LinkedList<T>* SortAlgorithms<T>::mergeSort(LinkedList<T> *list) {
    if(list->getSize() > 1){
        int nElementsLeft = list->getSize() / 2;
        LinkedList<T> *leftList = new LinkedList<T>();
        LinkedList<T> *rightList = new LinkedList<T>();


        for(int i = 0; i < nElementsLeft; i++){
            leftList->insertElement(list->getElement(i)->getData(), i);
        }

        for(int i = nElementsLeft; i < list->getSize(); i++){
            rightList->insertElement(list->getElement(i)->getData(), i - nElementsLeft);
        }

        leftList = mergeSort(leftList);
        rightList = mergeSort(rightList);

        int i = 0;
        int j = 0;
        int k = 0;
        while(leftList->getSize() != j && rightList->getSize() != k){
            Node<T> *node1 = list->getElement(i);
            if(leftList->getElement(j)->getData() < rightList->getElement(k)->getData()){
                Node<T> *node2 = leftList->getElement(j);
                node1->setData(node2->getData());
                i++;
                j++;
            } else{
                Node<T> *node2 = rightList->getElement(k);
                node1->setData(node2->getData());
                i++;
                k++;
            }
        }

        while (leftList->getSize() != j){
            Node<T> *node1 = list->getElement(i);
            Node<T> *node2 = leftList->getElement(j);
            node1->setData(node2->getData());
            i++;
            j++;
        }
        while (rightList->getSize() != k){
            Node<T> *node1 = list->getElement(i);
            Node<T> *node2 = rightList->getElement(k);
            node1->setData(node2->getData());
            i++;
            k++;
        }
    }
    return list;
}

template <class T>
void SortAlgorithms<T>::quickSort(LinkedList<T> *list) {
    quickSort(list, 0, list->getSize() -1);
}

template <class T>
void SortAlgorithms<T>::quickSort(LinkedList<T> *list, int first, int last) {
    int i = first;
    int j = last;
    Node<T> *pivot = list->getElement((first + last) / 2);
    do{
        while(list->getElement(i)->getData() < pivot->getData()){
            i++;
        }
        while(list->getElement(j)->getData() > pivot->getData()){
            j--;
        }


        if(i <= j){
            Node<T> *node1 = list->getElement(i);
            Node<T> *node2 = list->getElement(j);
            T aux = node1->getData();

            node1->setData(node2->getData());
            node2->setData(aux);
            i++;
            j--;
        }

    } while (i <= j);
    if(first < j){
        quickSort(list, first, j);
    }
    if(i < last){
        quickSort(list, i, last);
    }
}