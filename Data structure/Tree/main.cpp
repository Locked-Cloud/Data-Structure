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



/////////////////////////////////////////////






#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a node into the binary search tree
    Node* Insert(Node* r, int item) {
        if (r == nullptr) {
            Node* newnode = new Node(item);
            r = newnode;
        } else if (item < r->data) {
            r->left = Insert(r->left, item);
        } else {
            r->right = Insert(r->right, item);
        }
        return r;
    }

    void Insert(int item) {
        root = Insert(root, item);
    }

    // Preorder traversal (root -> left -> right)
    void Preorder(Node* r) {
        if (r == nullptr) return;
        cout << r->data << " ";
        Preorder(r->left);
        Preorder(r->right);
    }

    // Inorder traversal (left -> root -> right)
    void Inorder(Node* r) {
        if (r == nullptr) return;
        Inorder(r->left);
        cout << r->data << " ";
        Inorder(r->right);
    }

    // Postorder traversal (left -> right -> root)
    void Postorder(Node* r) {
        if (r == nullptr) return;
        Postorder(r->left);
        Postorder(r->right);
        cout << r->data << " ";
    }

    // Search for a node with a given key
    Node* Search(Node* r, int key) {
        if (r == nullptr || r->data == key)
            return r;
        else if (key < r->data)
            return Search(r->left, key);
        else
            return Search(r->right, key);
    }

    bool Search(int key) {
        Node* result = Search(root, key);
        return result != nullptr;
    }

    // Find the minimum value node in the tree
    Node* FindMin(Node* r) {
        while (r && r->left != nullptr)
            r = r->left;
        return r;
    }

    // Find the maximum value node in the tree
    Node* FindMax(Node* r) {
        while (r && r->right != nullptr)
            r = r->right;
        return r;
    }

    // Delete a node from the tree
    Node* Delete(Node* r, int key) {
        if (r == nullptr)
            return r;

        // Recursively find the node to delete
        if (key < r->data)
            r->left = Delete(r->left, key);
        else if (key > r->data)
            r->right = Delete(r->right, key);
        else {
            // Node to be deleted is found

            // Case 1: Node has no children (leaf node)
            if (r->left == nullptr && r->right == nullptr) {
                delete r;
                r = nullptr;
            }
            // Case 2: Node has one child (either left or right)
            else if (r->left == nullptr) {
                Node* temp = r;
                r = r->right;
                delete temp;
            }
            else if (r->right == nullptr) {
                Node* temp = r;
                r = r->left;
                delete temp;
            }
            // Case 3: Node has two children
            else {
                Node* temp = FindMin(r->right);
                r->data = temp->data;
                r->right = Delete(r->right, temp->data);
            }
        }
        return r;
    }

    // Wrapper function for delete
    void Delete(int key) {
        root = Delete(root, key);
    }
};

int main() {
    BST tree;
    tree.Insert(10);
    tree.Insert(8);
    tree.Insert(6);
    tree.Insert(7);
    tree.Insert(15);
    tree.Insert(12);
    tree.Insert(20);

    // Display the tree traversals
    cout << "Pre-order traversal: ";
    tree.Preorder(tree.root);
    cout << endl;

    cout << "In-order traversal: ";
    tree.Inorder(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.Postorder(tree.root);
    cout << endl;

    // Search for an element
    int key = 15;
    if (tree.Search(key))
        cout << "Element " << key << " found in the tree." << endl;
    else
        cout << "Element " << key << " not found in the tree." << endl;

    // Find minimum and maximum
    Node* min = tree.FindMin(tree.root);
    Node* max = tree.FindMax(tree.root);
    cout << "Minimum value in the tree: " << (min ? min->data : -1) << endl;
    cout << "Maximum value in the tree: " << (max ? max->data : -1) << endl;

    // Delete elements
    cout << "Deleting node with value 12..." << endl;
    tree.Delete(12);
    cout << "In-order traversal after deletion: ";
    tree.Inorder(tree.root);
    cout << endl;

    cout << "Deleting node with value 8..." << endl;
    tree.Delete(8);
    cout << "In-order traversal after deletion: ";
    tree.Inorder(tree.root);
    cout << endl;

    return 0;
}
