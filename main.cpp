#include <iostream>
#include "bst.hpp"

using namespace std;

int main() {
    BST<int> tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80};

    cout << "===== BINARY SEARCH TREE =====\n";

    cout << "\nInserting values: ";
    for (int value : values) {
        cout << value << " ";
        tree.insert(value);
    }

    cout << "\n\nIn-Order Traversal: ";
    tree.inorder();

    cout << "Pre-Order Traversal: ";
    tree.preorder();

    cout << "Post-Order Traversal: ";
    tree.postorder();

    cout << "\nSearch 40: ";
    cout << (tree.search(40) ? "Found" : "Not Found") << endl;

    cout << "Search 90: ";
    cout << (tree.search(90) ? "Found" : "Not Found") << endl;

    cout << "\nDeleting 30...\n";
    tree.remove(30);

    cout << "In-Order after deletion: ";
    tree.inorder();

    cout << "\nBST test completed successfully.\n";

    return 0;
}