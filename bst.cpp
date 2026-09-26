#include "bst.hpp"

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    destroy(root);
}

template <typename T>
typename BST<T>::Node* BST<T>::insert(Node* node, T value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    }
    else if (value > node->data) {
        node->right = insert(node->right, value);
    }

    return node;
}

template <typename T>
void BST<T>::insert(T value) {
    root = insert(root, value);
}

template <typename T>
bool BST<T>::search(Node* node, T value) const {
    if (node == nullptr) {
        return false;
    }

    if (node->data == value) {
        return true;
    }

    if (value < node->data) {
        return search(node->left, value);
    }

    return search(node->right, value);
}

template <typename T>
bool BST<T>::search(T value) const {
    return search(root, value);
}

template <typename T>
typename BST<T>::Node* BST<T>::remove(Node* node, T value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = remove(node->left, value);
    }
    else if (value > node->data) {
        node->right = remove(node->right, value);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* successor = node->right;

        while (successor->left != nullptr) {
            successor = successor->left;
        }

        node->data = successor->data;
        node->right = remove(node->right, successor->data);
    }

    return node;
}

template <typename T>
void BST<T>::remove(T value) {
    root = remove(root, value);
}

template <typename T>
void BST<T>::inorder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

template <typename T>
void BST<T>::inorder() const {
    inorder(root);
    cout << endl;
}

template <typename T>
void BST<T>::preorder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

template <typename T>
void BST<T>::preorder() const {
    preorder(root);
    cout << endl;
}

template <typename T>
void BST<T>::postorder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

template <typename T>
void BST<T>::postorder() const {
    postorder(root);
    cout << endl;
}

template <typename T>
void BST<T>::destroy(Node* node) {
    if (node == nullptr) {
        return;
    }

    destroy(node->left);
    destroy(node->right);

    delete node;
}

template class BST<int>;