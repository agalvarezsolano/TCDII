//
// Created by adrian on 30/11/17.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

/// Constructor
/// \tparam T Tipo de dato de la lista
template <class T>
LinkedList<T>::LinkedList() {
    size = 0;
}

/// Destructor
/// \tparam T Tipo de dato de la lista
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
/// Metodo para insertar un nuevo elemento al inicio de la lista.
/// \tparam T Tipo del dato que se desea insertar.
/// \param data Dato que se desea insertar.
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

/// Metodo que inserta un nuevo elemento al final de la lista
/// \tparam T Tipo de dato del elemento
/// \param data Dato del nuevo elemento
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

/// Metodo que inserta un nuevo elemento en una posicion especifica
/// \tparam T Tipo de dato del nuevo elemento
/// \param data Dato del nuevo elemento
/// \param position Posicion para el nuevo elemento
template <class T>
void LinkedList<T>::insertElement(T data, int position) {
    Node<T> *newNode = new Node<T>(data);
    Node<T> *current = first;

    if(first != NULL) {
        if (1 <= position && position < size) {
            for (int i = 0; i < (position - 1); ++i) { //Se detiene en el nodo anterior al de la posición deseada
                current = current->getNext();
            }
            newNode->setNext(current->getNext()); //Al nuevo nodo se le asigna la referencia al nodo siguiente
            current->setNext(newNode); //Al nodo anterior al nuevo nodo se le asigna la referencia al nuevo nodo
        }
        if (position == 0) { //caso en que la posicion deseada es como primer elemento
            newNode->setNext(first);
            first = newNode;
        }
        if (size <= position) {
            for (int i = 0; i < (size - 1); ++i) { //Se detiene en el último nodo de la lista
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    } else{
        first = newNode;
    }
    size++;
}

/// Metodo para obtener el elemento de una posicion especifica
/// \tparam T Tipo de dato del elemento deseado
/// \param position Posicion del elemento deseado
/// \return El elemento deseado
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

/// Metodo para establecer el dato que se estaba guardando en una posicion especifica
/// \tparam T Tipo del dato que se desea guardar
/// \param element Elemento que se desea almacenar
/// \param position Posicion en la que se desea almacenar el elemento
template <class T>
void LinkedList<T>::setElement(T element, int position) {
    Node<T> *current = first;

    if (first != NULL && position < size) {
        if (1 <= position && position < size) {
            for (int i = 0; i < (position - 1); i++) { //Se detiene en el nodo anterior al de la posición deseada
                current = current->getNext();
            }
            current->getNext()->setData(element);
        }
        if (position == 0) { //caso en que la posicion deseada es como primer elemento
            first->setData(element);
        }
        if (size <= position) {
            for (int i = 0; i < (size - 1); i++) { //Se detiene en el último nodo de la lista
                current = current->getNext();
            }
            current->getNext()->setData(element);
        }
    }
}

/// Metodo para eliminar un elemento en una posicion especifica
/// \tparam T Tipo de dato del los elementos de la lista
/// \param position Posicion del elemento a eliminar
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