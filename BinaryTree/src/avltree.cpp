#include <iostream>
#include <stdio.h>
#include "avltree.h"

using namespace std;

template<typename T>
void AVLTree<T>::insert(int data){
    this->root = NULL;
}

template<typename T>
void AVLTree<T>::insert(Node<T>* node, int data){
    cout << "insert" << endl;
}

template class AVLTree<int>;