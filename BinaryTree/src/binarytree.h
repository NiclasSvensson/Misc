#include "node.h"

template<typename T>
class BinaryTree {
    private:
        Node<T>* root;
        Node<T>* temp;
    public:
        BinaryTree();
        ~BinaryTree();
        void deleteNode(Node<T>* node);
        void insert(int data);
        void insert(Node<T>* node, int data);
        bool isBalanced();
        bool isBalanced(Node<T>* node);
        int getHeight();
        int getHeightOfNode(Node<T>* node);
        void invert();
        void invert(Node<T>* node);
        void print();
        void print(Node<T>* node, int level);
};