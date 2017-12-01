//
// Created by adrian on 30/11/17.
//

#include "BinaryTreeNode.h"

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T data1) {
    data = data1;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T data1, BinaryTreeNode<T>* left1, BinaryTreeNode<T>* right1) {
    data = data1;
    left = left1;
    right = right1;
}

template <class T>
T BinaryTreeNode<T>::getData() {
    return data;
}

template <class T>
void BinaryTreeNode<T>::setData(T data) {
    BinaryTreeNode<T>::data = data;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeft() {
    return left;
}

template <class T>
void BinaryTreeNode<T>::setLeft(BinaryTreeNode<T> *left) {
    BinaryTreeNode<T>::left = left;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRight() {
    return right;
}

template <class T>
void BinaryTreeNode<T>::setRight(BinaryTreeNode<T> *right) {
    BinaryTreeNode<T>::right = right;
}
