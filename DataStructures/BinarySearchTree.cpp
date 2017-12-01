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

/// Metodo que encuentra el descendiente menor del arbol
/// \tparam T Tipo de dato del arbol
/// \return El descendiente menor del nodo ingresado
template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::findMin() {
    return findMin(root);
}

/// Metodo que encuentra el descendiente menor de un nodo
/// \tparam T Tipo de dato del arbol
/// \param node Nodo actual en el recorrido
/// \return El hijo menor del nodo ingresado
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

/// Metodo para insertar un nuevo elemento en el arbol
/// \tparam T Tipo de dato del arbol
/// \param element Elemento a insertar
template <class T>
void BinarySearchTree<T>::insert(T element) {
    root = insert(element, root);
}

/// Metodo recursivo para insetar un nuevo elemento en el arbol
/// \tparam T Tipo de dato del arbol
/// \param element Elemento a insertar
/// \param current Nodo actual
/// \return Se retorna el current
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

/// Metodo para obtener un elemento del arbol
/// \tparam T Tipo de dato del arbol
/// \param element Elemento que se desea obtener
/// \return Elemento que se desea obtener
template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::getElement(T element) {
    return getElement(element, root);
}

///
/// \tparam T Metodo recursivo para obtener un elemento del arbol
/// \param element Elemento que se desea obtener
/// \param node Nodo actual en el recorrido
/// \return Elemento que se desea obtener
template <class T>
BinaryTreeNode<T>* BinarySearchTree<T>::getElement(T element, BinaryTreeNode<T> *node) {
    if(node == NULL){
        return NULL;
    } else if(node->getData() == element){ //Caso en el que se ha llegado al elemento deseado
        return node;
    } else if(node->getData() < element){ //Si el dato del nodo actual es menor al elemento deseado
        return getElement(element, node->getRight()); //Se continua con el hijo derecho del nodo actual
    } else{ //El dato del nodo actual es mayor al elemento deseado
        return getElement(element, node->getLeft()); //Se continua con el hijo izquierdo del nodo actual
    }
}

/// Metodo para eliminar un elemento del arbol
/// \tparam T Tipo de dato del arbol
/// \param element Elemento a eliminar
template <class T>
void BinarySearchTree<T>::remove(T element) {
    root = remove(element, root);
}

/// Metodo recursivo para eliminar un elemento del arbol
/// \tparam T Tipo de dato del arbol
/// \param element Elemento a eliminar
/// \param node Nodo actual
/// \return Nodo correspondiente segun la eliminacion
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


/// Metodo para imprimir el arbol en pre-orden
/// \tparam T Tipo de dato del arbol
/// \param node Nodo actual en el recorrido
template <class T>
void BinarySearchTree<T>::printPreOrder(BinaryTreeNode<T> *node) {
    if(node != NULL){
        cout << node->getData() << ", ";
        printPreOrder(node->getLeft());
        printPreOrder(node->getRight());
    }
}

/// Metodo para imprimir el arbol en orden
/// \tparam T Tipo de dato del arbol
/// \param node Nodo actual en el recorrido
template <class T>
void BinarySearchTree<T>::printInOrder(BinaryTreeNode<T> *node) {
    if(node != NULL){
        printInOrder(node->getLeft());
        cout << node->getData() << ", ";
        printInOrder(node->getRight());
    }
}

/// Metodo para imprimir el arbol en post-orden
/// \tparam T Tipo de dato del arbol
/// \param node Nodo actual en el recorrido
template <class T>
void BinarySearchTree<T>::printPostOrder(BinaryTreeNode<T> *node) {
    if(node != NULL){
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getData() << ", ";
    }
}