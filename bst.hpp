#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, T value);
    bool search(Node* node, T value) const;
    Node* remove(Node* node, T value);

    void inorder(Node* node) const;
    void preorder(Node* node) const;
    void postorder(Node* node) const;

    void destroy(Node* node);

public:
    BST();
    ~BST();

    void insert(T value);
    bool search(T value) const;
    void remove(T value);

    void inorder() const;
    void preorder() const;
    void postorder() const;
};

#endif