cmake_minimum_required(VERSION 2.8)
project(TCDII)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES DataStructures/Node.cpp DataStructures/Node.h DataStructures/LinkedList.cpp DataStructures/LinkedList.h DataStructures/BinarySearchTree.cpp DataStructures/BinarySearchTree.h DataStructures/BinaryTreeNode.cpp DataStructures/BinaryTreeNode.h DataStructures/AVLNode.cpp DataStructures/AVLNode.h DataStructures/AVLTree.cpp DataStructures/AVLTree.h main.cpp Sorts/SortAlgorithms.cpp Sorts/SortAlgorithms.h)
add_executable(TCDII ${SOURCE_FILES})