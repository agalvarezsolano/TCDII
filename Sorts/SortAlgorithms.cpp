//
// Created by adrian on 31/11/17.
//

#include "SortAlgorithms.h"
/// Metodo que implementa el algoritmo de ordenamiento burbuja
/// \tparam T Tipo de dato de la lista
/// \param list Lista que se desea ordenar
template <class T>
void SortAlgorithms<T>::bubbleSort(LinkedList<T> *list) {
    for(int i = list->getSize()- 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(list->getElement(j)->getData() > list->getElement(j + 1)->getData()){
                Node<T> *node1 = list->getElement(j);
                Node<T> *node2 = list->getElement(j + 1);
                T temp = node1->getData();
                node1->setData(node2->getData());
                node2->setData(temp);
            }
        }
    }
}

/// Metodo que implementa el algoritmo de ordenamiento por seleccion
/// \tparam T Tipo de dato de la lista
/// \param list Lista que se desea ordenar
template <class T>
void SortAlgorithms<T>::selectionSort(LinkedList<T> *list) {
    for(int i = 0; i < list->getSize() - 1; i++){

        //Se busca la posicion del elemento menor en la list
        int posMin = i;
        for (int x = i; x < list->getSize(); x++) {
            if (list->getElement(posMin)->getData() > list->getElement(x)->getData()) {
                posMin = x;
            }
        }
        //Se hace un swap de los elementos
        Node<T> *node1 = list->getElement(i);
        Node<T> *node2 = list->getElement(posMin);
        T temp = node1->getData();
        node1->setData(node2->getData());
        node2->setData(temp);
    }
}

/// Metodo que implementa el algoritmo de ordenamiento por insercion
/// \tparam T Tipo de dato de la lista
/// \param list Lista que se desea ordenar
template <class T>
void SortAlgorithms<T>::insertionSort(LinkedList<T> *list) {
    for(int i = 1; i < list->getSize(); i++){
        Node<T> *aux = new Node<T>(list->getElement(i)->getData());

        for(int x = i - 1; x >= 0; x--){
            if(list->getElement(x)->getData() > aux->getData()){
                Node<T> *node1 = list->getElement(x + 1);
                Node<T> *node2 = list->getElement(x);
                node1->setData(node2->getData());
                node2->setData(aux->getData());
            }
        }
    }
}

/// Metodo que implementa el algoritmo de ordenamiento MergeSort
/// \tparam T Tipo de dato de la lista
/// \param list Lista que se desea ordenar
/// \return La lista ordenada
template <class T>
LinkedList<T>* SortAlgorithms<T>::mergeSort(LinkedList<T> *list) {
    if(list->getSize() > 1){ //Hay algo que ordenar
        int nElementsLeft = list->getSize() / 2;
        //int nElementsRight = list->getSize() - nElementsLeft;
        LinkedList<T> *leftList = new LinkedList<T>(); //Lista de los elementos a la izquierda
        LinkedList<T> *rightList = new LinkedList<T>(); //Lista de los elemento a la derecha

        //Copiamos los elementos de la izquierda pertenecientes a la list original
        for(int i = 0; i < nElementsLeft; i++){
            leftList->insertElement(list->getElement(i)->getData(), i);
        }
        //Copiamos los elementos de la derecha pertenecientes a la list original
        for(int i = nElementsLeft; i < list->getSize(); i++){
            rightList->insertElement(list->getElement(i)->getData(), i - nElementsLeft);
        }

        leftList = mergeSort(leftList);
        rightList = mergeSort(rightList);

        int i = 0;
        int j = 0;
        int k = 0;
        while(leftList->getSize() != j && rightList->getSize() != k){
            Node<T> *node1 = list->getElement(i);
            if(leftList->getElement(j)->getData() < rightList->getElement(k)->getData()){
                Node<T> *node2 = leftList->getElement(j);
                node1->setData(node2->getData());
                i++;
                j++;
            } else{
                Node<T> *node2 = rightList->getElement(k);
                node1->setData(node2->getData());
                i++;
                k++;
            }
        }
        //Se unen las listas
        while (leftList->getSize() != j){
            Node<T> *node1 = list->getElement(i);
            Node<T> *node2 = leftList->getElement(j);
            node1->setData(node2->getData());
            i++;
            j++;
        }
        while (rightList->getSize() != k){
            Node<T> *node1 = list->getElement(i);
            Node<T> *node2 = rightList->getElement(k);
            node1->setData(node2->getData());
            i++;
            k++;
        }
    }
    return list;
}

/// Metodo que llama a al metodo que implementa el algoritmo de ordenamiento QuickSort
/// \tparam T Tipo de dato de la lista
/// \param list Lista que se desea ordenar
template <class T>
void SortAlgorithms<T>::quickSort(LinkedList<T> *list) {
    quickSort(list, 0, list->getSize() -1);
}

/// Metodo que implementa el algoritmo de ordenamiento QuickSort
/// \tparam T Tipo de dato de la lista
/// \param list Lista que se desea ordenar
/// \param first Posicion del primer elemento en la sublista actual
/// \param last Posicion del ultimo elemento en la sublista actual
template <class T>
void SortAlgorithms<T>::quickSort(LinkedList<T> *list, int first, int last) {
    int i = first;
    int j = last;
    Node<T> *pivot = list->getElement((first + last) / 2);
    do{
        while(list->getElement(i)->getData() < pivot->getData()){
            i++;
        }
        while(list->getElement(j)->getData() > pivot->getData()){
            j--;
        }

        //Se hace el intercambio
        if(i <= j){
            Node<T> *node1 = list->getElement(i);
            Node<T> *node2 = list->getElement(j);
            T aux = node1->getData();

            node1->setData(node2->getData());
            node2->setData(aux);
            i++;
            j--;
        }

    } while (i <= j);
    if(first < j){
        quickSort(list, first, j);
    }
    if(i < last){
        quickSort(list, i, last);
    }
}