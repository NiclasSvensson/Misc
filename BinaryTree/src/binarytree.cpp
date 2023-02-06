
#include <iostream>
#include <stdio.h>
#include <string>
#include "binarytree.h"

using namespace std;

template<typename T>
BinaryTree<T>::BinaryTree(){
    root = NULL;
    temp = NULL;
}

template<typename T>
BinaryTree<T>::~BinaryTree(){
    deleteNode(root);
}

template<typename T>
void BinaryTree<T>::deleteNode(Node<T> *node){
    if (node->left != NULL) deleteNode(node->left);
    if (node->right != NULL) deleteNode(node->right);
    delete node;
}

template<typename T>
void BinaryTree<T>::insert(T data){
    insert(root, data);
}

template<typename T>
Node<T>* BinaryTree<T>::insert(Node<T> *node, T data){
    if (node == NULL) return new Node<T>{data, NULL, NULL};
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}

template<typename T>
bool BinaryTree<T>::isBalanced(){
    return isBalanced(root);
}

template<typename T>
bool BinaryTree<T>::isBalanced(Node<T> *node){
    if (node == NULL) return true;
    if (abs(getHeightOfNode(node->left) - getHeightOfNode(node->right)) <= 1 &&
        isBalanced(node->left) && isBalanced(node->right)) return true;
    return false;
}

template<typename T>
int BinaryTree<T>::getBalance(){
    return getBalance(root);
}

template<typename T>
int BinaryTree<T>::getBalance(Node<T> *node){
    if (node == NULL) return 0;
    return getHeightOfNode(node->left) - getHeightOfNode(node->right);
}

template<typename T>
int BinaryTree<T>::getHeight(){
    return getHeightOfNode(root);
}

template<typename T>
int BinaryTree<T>::getHeightOfNode(Node<T> *node){
    if (node == NULL) return 0;
    return max(getHeightOfNode(node -> left), getHeightOfNode(node -> right)) + 1;
}

template<typename T>
void BinaryTree<T>::invert(){
    invert(root);
}

template<typename T>
void BinaryTree<T>::invert(Node<T> *node){
    if (node == NULL) return;
    temp = node -> left;
    node -> left = node -> right;
    node -> right = temp;
    invert(node->left);
    invert(node->right);
}


template<typename T>
bool BinaryTree<T>::search(T value){
    return search(root, value);
}

template<typename T>
bool BinaryTree<T>::search(Node<T> *node, T value){
    if (node == NULL) return false;
    else if (node -> data == value) return true;
    else if (node -> data < value) return search(node -> right, value);
    else return search(node -> left, value);
}

template<typename T>
void BinaryTree<T>::print(){
    print(root, 0);
}

template<typename T>
void BinaryTree<T>::print(Node<T> *node, int level){
    if (node == NULL) return;
    cout << string(level, '-') << node->data << endl;
    if (node->left != NULL) print(node->left, level + 1);
    if (node->right != NULL) print(node->right, level + 1);
}

template class BinaryTree<int>;