//
// Created by adrian on 30/11/17.
//

#ifndef SORTALGORITHMS_AVLTREE_H
#define SORTALGORITHMS_AVLTREE_H


#include "AVLNode.cpp"

template <class T>
class AVLTree {
public:
    AVLNode<T>* getRoot();

    AVLNode<T>* getElement(T element);

    void insert(T data);

    void remove(T element);

    void printPreOrder(AVLNode<T> *node);

    void printInOrder(AVLNode<T> *node);

    void printPostOrder(AVLNode<T> *node);

private:
    AVLNode<T> *root = NULL;

    int getBalanceFactor(AVLNode<T> *node);

    AVLNode<T>* leftRotation(AVLNode<T> *node);

    AVLNode<T>* rightRotation(AVLNode<T> *node);

    AVLNode<T>* doubleLeftRotation(AVLNode<T> *node);

    AVLNode<T>* doubleRightRotation(AVLNode<T> *node);

    AVLNode<T>* getElement(T element, AVLNode<T> *node);

    AVLNode<T>* insert(AVLNode<T> *newNode, AVLNode<T> *subTree);

    AVLNode<T>* remove(T element, AVLNode<T> *node);
};


#endif //SORTALGORITHMS_AVLTREE_H
