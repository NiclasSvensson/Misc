#ifndef AVLTREE
#define AVLTREE

//#include "node.h"
#include "binarytree.h"

template<typename T>
class AVLTree : public BinaryTree<T> {
    public:
        void insert(int data);
        void insert(Node<T>* node, int data);
};

#endif