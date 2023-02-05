#ifndef AVLTREE
#define AVLTREE

#include "binarytree.h"

template<typename T>
class AVLTree : public BinaryTree<T> {
    private:
        Node<T>* rotateLeft(Node<T> *node);
        Node<T>* rotateRight(Node<T> *node);
        Node<T>* insert(Node<T> *node, T data);
    public:
        void insert(T data);
};

#endif