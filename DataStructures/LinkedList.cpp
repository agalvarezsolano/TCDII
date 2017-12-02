//
// Created by adrian on 30/11/17.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;


template <class T>
LinkedList<T>::LinkedList() {
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    for (int i = 0; i < (size - 1); ++i) {
        Node<T> *current = first;
        first = first->getNext();
        delete current;
    }
}

template <class T>
int LinkedList<T>::getSize() {
    return size;
}

template <class T>
void LinkedList<T>::insertAtFirst(T data) {
    Node<T> *newNode = new Node<T>(data);
    if(first == NULL){
        first = newNode;
    } else {
        newNode->setNext(first);
        first = newNode;
    }
    size++;
}

template <class T>
void LinkedList<T>::insertAtEnd(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (first == NULL) {
        first = newNode;
    } else {
        Node<T> *current = first;
        while (current->getNext() != NULL) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}

template <class T>
void LinkedList<T>::insertElement(T data, int position) {
    Node<T> *newNode = new Node<T>(data);
    Node<T> *current = first;

    if(first != NULL) {
        if (1 <= position && position < size) {
            for (int i = 0; i < (position - 1); ++i) {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
        }
        if (position == 0) {
            newNode->setNext(first);
            first = newNode;
        }
        if (size <= position) {
            for (int i = 0; i < (size - 1); ++i) {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    } else{
        first = newNode;
    }
    size++;
}

template <class T>
Node<T>* LinkedList<T>::getElement(int position) {
    Node<T> *current = first;

    if(position < size && position >= 0) {
        for (int i = 0; i < position; i++) {
            current = current->getNext();
        }
    } else{
        return NULL;
    }
    return current;
}

template <class T>
void LinkedList<T>::setElement(T element, int position) {
    Node<T> *current = first;

    if (first != NULL && position < size) {
        if (1 <= position && position < size) {
            for (int i = 0; i < (position - 1); i++) {
                current = current->getNext();
            }
            current->getNext()->setData(element);
        }
        if (position == 0) {
            first->setData(element);
        }
        if (size <= position) {
            for (int i = 0; i < (size - 1); i++) {
                current = current->getNext();
            }
            current->getNext()->setData(element);
        }
    }
}

template <class T>
void LinkedList<T>::deleteElement(int position) {
    if (position == 0 && size > 0) {
        first = first->getNext();
    } else {
        if (position <= (size - 1)) {
            Node<T> *current = first;
            for (int i = 0; i < (position - 1); i++) {
                current = current->getNext();
            }

            current->setNext(current->getNext()->getNext());
            size--;
        }
    }
}

template <class T>
void LinkedList<T>::printList() {
    Node<T> *current = first;
    while(current != NULL){
        cout << (current->getData()) << " ";
        current = current->getNext();
    }
    cout << endl;
}