//
// Created by adrian on 30/11/17.
//

#ifndef SORTALGORITHMS_BINARYSEARCHTREE_H
#define SORTALGORITHMS_BINARYSEARCHTREE_H

#include "BinaryTreeNode.cpp"

template <class T>
class BinarySearchTree {
private:
    BinaryTreeNode<T> *root;

    BinaryTreeNode<T>* getElement(T element, BinaryTreeNode<T> *node);

    BinaryTreeNode<T>* findMin(BinaryTreeNode<T>* node);

    BinaryTreeNode<T>* insert(T element, BinaryTreeNode<T> *current);

    BinaryTreeNode<T>* remove(T element, BinaryTreeNode<T> *node);

public:
    BinarySearchTree();

    ~BinarySearchTree();

    BinaryTreeNode<T>* getRoot();

    BinaryTreeNode<T>* findMin();

    void insert(T element);

    BinaryTreeNode<T>* getElement(T element);

    void remove(T element);

    void printPreOrder(BinaryTreeNode<T> *node);

    void printInOrder(BinaryTreeNode<T> *node);

    void printPostOrder(BinaryTreeNode<T> *node);
};


#endif //SORTALGORITHMS_BINARYSEARCHTREE_H
