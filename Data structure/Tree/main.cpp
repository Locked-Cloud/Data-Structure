#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
public:
    Node* root;

    // Constructor to initialize the tree with a null root
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a new node in the tree
    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
        return root;
    }

    // Function to display the tree (in-order traversal)
    void inOrderTraversal(Node* root) {
        if (root == nullptr) return;

        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    // Function to search for a node in the tree
    bool search(Node* root, int data) {
        if (root == nullptr) {
            return false;
        }

        if (root->data == data) {
            return true;
        } else if (data < root->data) {
            return search(root->left, data);
        } else {
            return search(root->right, data);
        }
    }
};

int main() {
    BinaryTree tree;

    // Insert elements into the tree
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    // Display the tree in in-order traversal
    cout << "In-order traversal: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;

    // Search for an element in the tree
    int value;
    cout << "Enter value to search: ";
    cin >> value;
    if (tree.search(tree.root, value)) {
        cout << value << " is found in the tree." << endl;
    } else {
        cout << value << " is not found in the tree." << endl;
    }

    return 0;
}
