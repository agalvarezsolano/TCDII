//
// Created by adrian on 30/11/17.
//

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::getRoot() {
    return root;
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::findMin() {
    return findMin(root);
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::findMin(BinaryTreeNode<T> *node) {
    if(node == NULL){
        return NULL;
    } else if(node->getLeft() == NULL){
        return node;
    } else{
        return findMin(node->getLeft());
    }
}

template <class T>
void BinarySearchTree<T>::insert(T element) {
    root = insert(element, root);
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::insert(T element, BinaryTreeNode<T> *current) {
    if(current == NULL){
        BinaryTreeNode<T> *node = new BinaryTreeNode<T>(element);
        return node;
    } else if(current->getData() > element){
        current->setLeft(insert(element, current->getLeft()));
    } else if(current->getData() < element){
        current->setRight(insert(element, current->getRight()));
    }
    return current;
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::getElement(T element) {
    return getElement(element, root);
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::getElement(T element, BinaryTreeNode<T> *node) {
    if(node == NULL){
        return NULL;
    } else if(node->getData() == element){
        return node;
    } else if(node->getData() < element){
        return getElement(element, node->getRight());
    } else{
        return getElement(element, node->getLeft());
    }
}

template <class T>
void BinarySearchTree<T>::remove(T element) {
    root = remove(element, root);
}

template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::remove(T element, BinaryTreeNode<T> *node) {
    if(node == NULL){
        return node;
    }
    if(node->getData() > element){
        node->setLeft(remove(element, node->getLeft()));
    } else if(node->getData() < element){
        node->setRight(remove(element, node->getRight()));
    } else if(node->getLeft() != NULL && node->getRight() != NULL){
        node->setData(findMin(node->getRight())->getData());
        node->setRight(remove(node->getData(), node->getRight()));
    } else{
        node = node->getLeft() != NULL ? node->getLeft(): node->getRight();
    }
    return node;
}

template <class T>
void BinarySearchTree<T>::printPreOrder(BinaryTreeNode<T> *node) {
    if(node != NULL){
        cout << node->getData() << ", ";
        printPreOrder(node->getLeft());
        printPreOrder(node->getRight());
    }
}

template <class T>
void BinarySearchTree<T>::printInOrder(BinaryTreeNode<T> *node) {
    if(node != NULL){
        printInOrder(node->getLeft());
        cout << node->getData() << ", ";
        printInOrder(node->getRight());
    }
}

template <class T>
void BinarySearchTree<T>::printPostOrder(BinaryTreeNode<T> *node) {
    if(node != NULL){
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getData() << ", ";
    }
}