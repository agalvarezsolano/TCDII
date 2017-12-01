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

/// Metodo para obtener un elemento del arbol
/// \tparam T Tipo de dato del arbol
/// \param element Elemento que se desea obtener
/// \return Elemento que se desea obtener
template <class T>
AVLNode<T>* AVLTree<T>::getElement(T element) {
    return  getElement(element, root);
}

/// Metodo recursivo para obtener un elemento del arbol
/// \tparam T Tipo de dato del arbol
/// \param element Elemento que se desea obtener
/// \param node Nodo actual en el recorrido
/// \return Elemento que se desea obtener
template <class T>
AVLNode<T>* AVLTree<T>::getElement(T element, AVLNode<T> *node) {
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

/// Metodo para obtener el factor de balance de un nodo AVL
/// \tparam T Tipo de dato del nodo
/// \param node Nodo al que se le desea obtener el factor de balance
/// \return El factor de balance del nodo ingresado
template <class T>
int AVLTree<T>::getBalanceFactor(AVLNode<T> *node) {
    if(node == NULL) return -1; //Caso en el que el nodo es nulo
    else return node->getBalanceFactor(); //Se obtiene el factor de balance del nodo
}

/// Rotacion simple izquierda
/// \tparam T Tipo de dato del nodo
/// \param node Nodo que se desea balancear
/// \return Nodo correspondiente segun el resultado del balanceo
template <class T>
AVLNode<T>* AVLTree<T>::leftRotation(AVLNode<T> *node) {
    AVLNode<T> *aux = node->getLeft();

    node->setLeft(aux->getRight());
    aux->setRight(node);

    //Se calculan los nuevos factores de balance
    int balanceFactor1 = getBalanceFactor(node->getLeft()) > getBalanceFactor(node->getRight()) ? getBalanceFactor(node->getLeft()) : getBalanceFactor(node->getRight());
    int balanceFactor2 = getBalanceFactor(aux->getLeft()) > getBalanceFactor(aux->getRight()) ? getBalanceFactor(aux->getLeft()) : getBalanceFactor(aux->getRight());

    node->setBalanceFactor(balanceFactor1 + 1);
    aux->setBalanceFactor(balanceFactor2 + 1);

    return aux;
}

/// Rotacion simple derecha
/// \tparam T Tipo de dato del nodo
/// \param node Nodo que se desea balancear
/// \return Nodo correspondiente segun el resultado del balanceo
template <class T>
AVLNode<T>* AVLTree<T>::rightRotation(AVLNode<T> *node) {
    AVLNode<T> *aux = node->getRight();

    node->setRight(aux->getLeft());
    aux->setLeft(node);

    //Se calculan los nuevos factores de balance
    int balanceFactor1 = getBalanceFactor(node->getLeft()) > getBalanceFactor(node->getRight()) ? getBalanceFactor(node->getLeft()) : getBalanceFactor(node->getRight());
    int balanceFactor2 = getBalanceFactor(aux->getLeft()) > getBalanceFactor(aux->getRight()) ? getBalanceFactor(aux->getLeft()) : getBalanceFactor(aux->getRight());


    node->setBalanceFactor(balanceFactor1 + 1);
    aux->setBalanceFactor(balanceFactor2 + 1);

    return aux;
}

/// Rotacion doble izquierda
/// \tparam T Tipo de dato del nodo
/// \param node Nodo que se desea balancear
/// \return Nodo correspondiente segun el resultado del balanceo
template <class T>
AVLNode<T>* AVLTree<T>::doubleLeftRotation(AVLNode<T> *node) {
    node->setLeft(rightRotation(node->getLeft()));
    AVLNode<T> *aux = leftRotation(node);
    return aux;
}

/// Rotacion doble derecha
/// \tparam T Tipo de dato del nodo
/// \param node Nodo que se desea balancear
/// \return Nodo correspondiente segun el resultado del balanceo
template <class T>
AVLNode<T>* AVLTree<T>::doubleRightRotation(AVLNode<T> *node) {
    node->setRight(leftRotation(node->getRight()));
    AVLNode<T> *aux = rightRotation(node);
    return aux;
}

/// Metodo para insertar un nuevo elemento en el arbol
/// \tparam T Tipo de dato del arbol
/// \param data Dato que se desea insertar
template <class T>
void AVLTree<T>::insert(T data) {
    AVLNode<T> *newNode = new AVLNode<T>(data); //Se crea un nuevo nodo con el dato ingresado

    if(root == NULL){ //Caso en el que el arbol esta vacio
        root = newNode;
    } else{ //Caso en el que el arbol no esta vacio
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
            if(getBalanceFactor(subTree->getLeft()) - getBalanceFactor(subTree->getRight()) == 2){ //Si el arbol esta desvalanceado
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

    //Se actualiza el factor de balance
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

/// Metodo para eliminar un elemento del arbol
/// \tparam T Tipo de dato del arbol
/// \param element Elemento a eliminar
template <class T>
void AVLTree<T>::remove(T element) {
    root = remove(element, root);
}

/// Metodo auxiliar para eliminar el elemento ingresado del arbol
/// \tparam T Tipo de dato del nodo
/// \param element Elemento a eliminar
/// \param node Nodo actual
/// \return Nodo correspondiente segun el resultado
template <class T>
AVLNode<T>* AVLTree<T>::remove(T element, AVLNode<T> *node) {
    if(node == NULL){
        return NULL;
    } else{
        if(node->getData() < element){ //Si es menor                         node.getData() < element
            node->setRight(remove(element, node->getRight()));
        } else if(node->getData() > element){ //Si es mayor                               node.getData() > element
            node->setLeft(remove(element, node->getLeft()));
        } else if(node->getLeft() == NULL){ //Caso en el que el nodo no tiene hijo izquierdo
            node = node->getRight();
        } else if(node->getRight() == NULL){ //Caso en el que el nodo no tiene hijo izquierdo
            node = node->getLeft();
        } else if(getBalanceFactor(node->getLeft()) > getBalanceFactor(node->getRight())){ //Caso en el que ningun descendiente es nulo
            node = rightRotation(node);
            node->setLeft(remove(element, node->getLeft()));
        } else{
            node = leftRotation(node);
            node->setRight(remove(element, node->getRight()));
        }
        //Actualizamos el factor de balance
        if(node != NULL){
            node->setBalanceFactor(getBalanceFactor(node->getLeft()) + getBalanceFactor(node->getRight()));
        }
    }
    return node;
}

/// Metodo para imprimir el arbol en pre-orden
/// \tparam T Tipo de dato del arbol
/// \param node Nodo actual en el recorrido
template <class T>
void AVLTree<T>::printPreOrder(AVLNode<T> *node) {
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
void AVLTree<T>::printInOrder(AVLNode<T> *node) {
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
void AVLTree<T>::printPostOrder(AVLNode<T> *node) {
    if(node != NULL){
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getData() << ", ";
    }
}