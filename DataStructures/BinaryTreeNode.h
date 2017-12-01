//
// Created by adrian on 30/11/17.
//

#ifndef SORTALGORITHMS_BINARYTREENODE_H
#define SORTALGORITHMS_BINARYTREENODE_H

#import <iostream>

template <class T>
class BinaryTreeNode {
private:
    T data;
    BinaryTreeNode<T> *left = NULL;
    BinaryTreeNode<T> *right = NULL;

public:
    BinaryTreeNode(T data1);

    BinaryTreeNode(T data1, BinaryTreeNode<T>* left1, BinaryTreeNode<T>* right1);

    T getData();

    void setData(T data);

    BinaryTreeNode<T>* getLeft();

    void setLeft(BinaryTreeNode<T> *left);

    BinaryTreeNode<T>* getRight();

    void setRight(BinaryTreeNode<T> *right);
};


#endif //SORTALGORITHMS_BINARYTREENODE_H
