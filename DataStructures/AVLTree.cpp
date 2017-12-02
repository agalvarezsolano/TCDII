//
// Created by adrian on 30/11/17.
//

#include <iostream>
#include "AVLTree.h"

using namespace std;

template <class T>
AVLNode<T>* AVLTree<T>::getRoot() {
    return root;
}

template <class T>
AVLNode<T>* AVLTree<T>::getElement(T element) {
    return  getElement(element, root);
}


template <class T>
AVLNode<T>* AVLTree<T>::getElement(T element, AVLNode<T> *node) {
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
int AVLTree<T>::getBalanceFactor(AVLNode<T> *node) {
    if(node == NULL) return -1;
    else return node->getBalanceFactor();
}

template <class T>
AVLNode<T>* AVLTree<T>::leftRotation(AVLNode<T> *node) {
    AVLNode<T> *aux = node->getLeft();

    node->setLeft(aux->getRight());
    aux->setRight(node);

    int balanceFactor1 = getBalanceFactor(node->getLeft()) > getBalanceFactor(node->getRight()) ? getBalanceFactor(node->getLeft()) : getBalanceFactor(node->getRight());
    int balanceFactor2 = getBalanceFactor(aux->getLeft()) > getBalanceFactor(aux->getRight()) ? getBalanceFactor(aux->getLeft()) : getBalanceFactor(aux->getRight());

    node->setBalanceFactor(balanceFactor1 + 1);
    aux->setBalanceFactor(balanceFactor2 + 1);

    return aux;
}

template <class T>
AVLNode<T>* AVLTree<T>::rightRotation(AVLNode<T> *node) {
    AVLNode<T> *aux = node->getRight();

    node->setRight(aux->getLeft());
    aux->setLeft(node);

    int balanceFactor1 = getBalanceFactor(node->getLeft()) > getBalanceFactor(node->getRight()) ? getBalanceFactor(node->getLeft()) : getBalanceFactor(node->getRight());
    int balanceFactor2 = getBalanceFactor(aux->getLeft()) > getBalanceFactor(aux->getRight()) ? getBalanceFactor(aux->getLeft()) : getBalanceFactor(aux->getRight());


    node->setBalanceFactor(balanceFactor1 + 1);
    aux->setBalanceFactor(balanceFactor2 + 1);

    return aux;
}

template <class T>
AVLNode<T>* AVLTree<T>::doubleLeftRotation(AVLNode<T> *node) {
    node->setLeft(rightRotation(node->getLeft()));
    AVLNode<T> *aux = leftRotation(node);
    return aux;
}

template <class T>
AVLNode<T>* AVLTree<T>::doubleRightRotation(AVLNode<T> *node) {
    node->setRight(leftRotation(node->getRight()));
    AVLNode<T> *aux = rightRotation(node);
    return aux;
}

template <class T>
void AVLTree<T>::insert(T data) {
    AVLNode<T> *newNode = new AVLNode<T>(data);

    if(root == NULL){
        root = newNode;
    } else{
        root = insert(newNode, root);
    }
}

template <class T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T> *newNode, AVLNode<T> *subTree) {
    AVLNode<T> *newFather = subTree;

    if(newNode->getData() < subTree->getData()){
        if(subTree->getLeft() == NULL){
            subTree->setLeft(newNode);
        } else{
            subTree->setLeft(insert(newNode, subTree->getLeft()));
            if(getBalanceFactor(subTree->getLeft()) - getBalanceFactor(subTree->getRight()) == 2){
                if(newNode->getData() < subTree->getLeft()->getData()){
                    newFather = leftRotation(subTree);
                } else{
                    newFather = doubleLeftRotation(subTree);
                }
            }
        }
    } else if(newNode->getData() > subTree->getData()){
        if(subTree->getRight() == NULL){
            subTree->setRight(newNode);
        } else{
            subTree->setRight(insert(newNode, subTree->getRight()));
            if((getBalanceFactor(subTree->getRight()) - getBalanceFactor(subTree->getLeft()) == 2)){
                if(newNode->getData() > subTree->getRight()->getData()){
                    newFather = rightRotation(subTree);
                } else{
                    newFather = doubleRightRotation(subTree);
                }
            }
        }
    }

    if((subTree->getLeft() == NULL) && (subTree->getRight() != NULL)){
        subTree->setBalanceFactor(subTree->getRight()->getBalanceFactor() + 1);
    } else if((subTree->getRight() == NULL) && (subTree->getLeft() != NULL)){
        subTree->setBalanceFactor(subTree->getLeft()->getBalanceFactor() + 1);
    } else{
        int balanceFactor = getBalanceFactor(subTree->getLeft()) > getBalanceFactor(subTree->getRight()) ? getBalanceFactor(subTree->getLeft()) : getBalanceFactor(subTree->getRight());
        subTree->setBalanceFactor(balanceFactor + 1);
    }
    return newFather;
}

template <class T>
void AVLTree<T>::remove(T element) {
    root = remove(element, root);
}


template <class T>
AVLNode<T>* AVLTree<T>::remove(T element, AVLNode<T> *node) {
    if(node == NULL){
        return NULL;
    } else{
        if(node->getData() < element){
            node->setRight(remove(element, node->getRight()));
        } else if(node->getData() > element){
            node->setLeft(remove(element, node->getLeft()));
        } else if(node->getLeft() == NULL){
            node = node->getRight();
        } else if(node->getRight() == NULL){
            node = node->getLeft();
        } else if(getBalanceFactor(node->getLeft()) > getBalanceFactor(node->getRight())){
            node = rightRotation(node);
            node->setLeft(remove(element, node->getLeft()));
        } else{
            node = leftRotation(node);
            node->setRight(remove(element, node->getRight()));
        }

        if(node != NULL){
            node->setBalanceFactor(getBalanceFactor(node->getLeft()) + getBalanceFactor(node->getRight()));
        }
    }
    return node;
}

template <class T>
void AVLTree<T>::printPreOrder(AVLNode<T> *node) {
    if(node != NULL){
        cout << node->getData() << ", ";
        printPreOrder(node->getLeft());
        printPreOrder(node->getRight());
    }
}

template <class T>
void AVLTree<T>::printInOrder(AVLNode<T> *node) {
    if(node != NULL){
        printInOrder(node->getLeft());
        cout << node->getData() << ", ";
        printInOrder(node->getRight());
    }
}

template <class T>
void AVLTree<T>::printPostOrder(AVLNode<T> *node) {
    if(node != NULL){
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getData() << ", ";
    }
}