//
// Created by adrian on 30/11/17.
//

#include "AVLNode.h"

template <class T>
AVLNode<T>::AVLNode(T data) {
    AVLNode<T>::data = data;
}

template <class T>
T AVLNode<T>::getData() {
    return data;
}

template <class T>
void AVLNode<T>::setData(T data) {
    AVLNode<T>::data = data;
}

template <class T>
int AVLNode<T>::getBalanceFactor() {
    return balanceFactor;
}

template <class T>
void AVLNode<T>::setBalanceFactor(int balanceFactor) {
    AVLNode<T>::balanceFactor = balanceFactor;
}

template <class T>
AVLNode<T> *AVLNode<T>::getLeft() {
    return left;
}

template <class T>
void AVLNode<T>::setLeft(AVLNode *left) {
    AVLNode<T>::left = left;
}

template <class T>
AVLNode<T> *AVLNode<T>::getRight() {
    return right;
}

template <class T>
void AVLNode<T>::setRight(AVLNode *right) {
    AVLNode<T>::right = right;
}
