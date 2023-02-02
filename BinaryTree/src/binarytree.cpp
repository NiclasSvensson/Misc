
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
    if (root != NULL) {
        if (root->left != NULL) deleteNode(root->left);
        if (root->right != NULL) deleteNode(root->right);
        delete root;
    }
}

template<typename T>
void BinaryTree<T>::deleteNode(Node<T>* node){
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
bool BinaryTree<T>::isBalanced(){
    if (root == NULL) return true;
    if (abs(getHeightOfNode(root->left) - getHeightOfNode(root->right)) <= 1 &&
        isBalanced(root->left) && isBalanced(root->right)) return true;
    return false;
}

template<typename T>
bool BinaryTree<T>::isBalanced(Node<T>* node){
    if (node == NULL) return true;
    if (abs(getHeightOfNode(node->left) - getHeightOfNode(node->right)) <= 1 &&
        isBalanced(node->left) && isBalanced(node->right)) return true;
    return false;
}

template<typename T>
int BinaryTree<T>::getHeight(){
    return getHeightOfNode(root);
}

template<typename T>
int BinaryTree<T>::getHeightOfNode(Node<T>* node){
    if (node == NULL) return 0;
    return max(getHeightOfNode(node -> left), getHeightOfNode(node -> right)) + 1;
}

template<typename T>
void BinaryTree<T>::invert(){
    if (root == NULL) return;
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    invert(root->left);
    invert(root->right);
}

template<typename T>
void BinaryTree<T>::invert(Node<T>* node){
    if (node == NULL) return;
    temp = node -> left;
    node -> left = node -> right;
    node -> right = temp;
    invert(node->left);
    invert(node->right);
}


template<typename T>
bool BinaryTree<T>::search(T value){
    if (root == NULL) return false;
    if (root -> data == value) return true;
    if (search(root -> left, value)) return true;
    if (search(root -> right, value)) return true;
    return false;
}

template<typename T>
bool BinaryTree<T>::search(Node<T>* node, T value){
    if (node == NULL) return false;
    if (node -> data == value) return true;
    if (search(node -> left, value)) return true;
    if (search(node -> right, value)) return true;
    return false;
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