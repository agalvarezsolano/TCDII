//
// Created by adrian on 30/11/17.
//

#ifndef SORTALGORITHMS_NODE_H
#define SORTALGORITHMS_NODE_H

#import "iostream"
template <class T>
class Node {
private:
    T data;
    Node<T> *next;

public:
    Node(T data);

    void setData(T data);

    T getData();

    void setNext(Node *next);

    Node* getNext();
};


#endif //SORTALGORITHMS_NODE_H
