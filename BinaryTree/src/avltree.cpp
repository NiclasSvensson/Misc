#include <iostream>
#include <stdio.h>
#include "avltree.h"

using namespace std;

template<typename T>
void AVLTree<T>::insert(T data){
    this->root = insert(this->root, data);
}

template<typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, T data){
    if (node == NULL) return (new Node<T>{data, NULL, NULL});
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    else return node;

    int balance = this->getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);
    if (balance > 1 && data > node->left->data){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && data < node->right->data){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

template<typename T>
Node<T>* AVLTree<T>::rotateRight(Node<T> *y) {
    Node<T> *x = y->left;
    Node<T> *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

template<typename T>
Node<T>* AVLTree<T>::rotateLeft(Node<T> *x) {
    Node<T> *y = x->right;
    Node<T> *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

template class AVLTree<int>;