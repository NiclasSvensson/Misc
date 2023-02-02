#ifndef NODE
#define NODE

template <typename T>
struct Node {
    T data;
    Node<T>* right;
    Node<T>* left;
};

#endif