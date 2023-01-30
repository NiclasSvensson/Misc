template <typename T>
struct Node {
    T data;
    Node<T>* right;
    Node<T>* left;
};