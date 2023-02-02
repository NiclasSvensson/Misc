#include <iostream>

#include "binarytree.h"
#include "avltree.h"

using namespace std;

int main(){
    cout << "Binary Tree" << endl;
    BinaryTree<int> tree;
    //AVLTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(10);
    tree.insert(13);
    tree.insert(14);
    tree.insert(7);
    tree.insert(12);
    tree.insert(6);
    tree.insert(0);
    tree.insert(15);
    tree.insert(16);

    tree.print();
    cout << "Inverting tree" << endl;
    tree.invert();
    tree.print();
    cout << "Tree Height: " << tree.getHeight() << endl;
    cout << "Is tree balanced: " << tree.isBalanced() << endl;
    cout << "Is 2 in tree: " << tree.search(2) << endl;
    cout << "Is 7 in tree: " << tree.search(7) << endl;
    cout << "Is 17 in tree: " << tree.search(17) << endl;
    cout << "Is 5 in tree: " << tree.search(5) << endl;
    return 0;
}