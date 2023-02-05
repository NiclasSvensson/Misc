#ifndef BINARYTREE
#define BINARYTREE

#include "node.h"

template<typename T>
class BinaryTree {
    private:
        Node<T> *temp;
        Node<T>* insert(Node<T> *node, T data);
    protected:
        Node<T> *root;
        bool isBalanced(Node<T> *node);
        int getBalance(Node<T> *node);
        int getHeightOfNode(Node<T> *node);
        void invert(Node<T> *node);
        bool search(Node<T> *node, T value);
        void print(Node<T> *node, int level);
        void deleteNode(Node<T> *node);
    public:
        BinaryTree();
        ~BinaryTree();
        void insert(T data);
        bool isBalanced();
        int getBalance();
        int getHeight();
        void invert();
        bool search(T value);
        void print();
};

#endif