//
// Created by adrian on 30/11/17.
//

#include "Node.h"

template <class T>
Node<T>::Node(T data) {
    Node::data = data;
    Node::next = NULL;
}

template <class T>
void Node<T>::setData(T data) {
    Node::data = data;
}

template <class T>
T Node<T>::getData() {
    return Node::data;
}

template <class T>
void Node<T>::setNext(Node *next) {
    Node::next = next;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return Node::next;
}