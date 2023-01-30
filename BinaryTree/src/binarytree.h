#include "node.h"

template<typename T>
class BinaryTree {
    private:
        Node<T>* root;
    public:
        BinaryTree();
        ~BinaryTree();
        void deleteNode(Node<T>* node);
        void insert(int data);
        void insert(Node<T>* node, int data);
        void print();
        void print(Node<T>* node, int level);
};