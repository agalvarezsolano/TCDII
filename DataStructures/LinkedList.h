//
// Created by adrian on 30/11/17.
//

#ifndef SORTALGORITHMS_LINKEDLIST_H
#define SORTALGORITHMS_LINKEDLIST_H


#include "Node.cpp"

template <class T>
class LinkedList {
private:
    Node<T> *first = NULL;
    int size;

public:
    LinkedList();

    ~LinkedList();

    int getSize();

    void insertAtFirst(T data);

    void insertAtEnd(T data);

    void insertElement(T data, int position);

    Node<T>* getElement(int position);

    void setElement(T element, int position);

    void deleteElement(int position);

    void printList();
};


#endif //SORTALGORITHMS_LINKEDLIST_H
