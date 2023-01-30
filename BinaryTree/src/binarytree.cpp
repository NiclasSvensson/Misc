
#include <iostream>
#include <stdio.h>
#include <string>
#include "binarytree.h"

using namespace std;

template<typename T>
BinaryTree<T>::BinaryTree(){
    root = NULL;
}

template<typename T>
BinaryTree<T>::~BinaryTree(){
    if (root != NULL) {
        //cout << root->data << endl;
        if (root->left != NULL) deleteNode(root->left);
        if (root->right != NULL) deleteNode(root->right);
        delete root;
    }
}

template<typename T>
void BinaryTree<T>::deleteNode(Node<T>* node){
    //cout << node->data << endl;
    if (node->left != NULL) deleteNode(node->left);
    if (node->right != NULL) deleteNode(node->right);
    delete node;
}

template<typename T>
void BinaryTree<T>::insert(int data){
    if (root == NULL){
        root = new Node<T>{data, NULL, NULL};
    } else if (root->data >= data){
        if(root->left == NULL){
            root->left = new Node<T>{data, NULL, NULL};
        } else {
            insert(root->left, data);
        }
    } else {
        if(root->right == NULL){
            root->right = new Node<T>{data, NULL, NULL};
        } else {
            insert(root->right, data);
        }
    }
}

template<typename T>
void BinaryTree<T>::insert(Node<T>* node, int data){
    if (node->data >= data){
        if(node->left == NULL){
            node->left = new Node<T>{data, NULL, NULL};
        } else {
            insert(node->left, data);
        }
    } else {
        if(node->right == NULL){
            node->right = new Node<T>{data, NULL, NULL};
        } else {
            insert(node->right, data);
        }
    }
}

template<typename T>
void BinaryTree<T>::print(){
    if (root == NULL) return;
    cout << root->data << endl;
    print(root->left, 1);
    print(root->right, 1);
}

template<typename T>
void BinaryTree<T>::print(Node<T>* node, int level){
    if (node == NULL) return;
    cout << string(level, '-') << node->data << endl;
    if (node->left != NULL) print(node->left, level + 1);
    if (node->right != NULL) print(node->right, level + 1);
}

template class BinaryTree<int>;