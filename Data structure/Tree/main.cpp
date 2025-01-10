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
    Node* left, * right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* Insert(Node* r, int item) {
        if (r == NULL) {
            Node* newnode = new Node(item);
            r = newnode;
        }
        else if (item < r->data)
            r->left = Insert(r->left, item);
        else
            r->right = Insert(r->right, item);

        return r;
    }

    void Insert(int item) {
        root = Insert(root, item);
    }

    void Preorder(Node* r) { // root -> left -> right
        if (r == NULL)
            return;
        cout << r->data << "\t";
        Preorder(r->left);
        Preorder(r->right);
    }

    void Inorder(Node* r) { // left -> root -> right
        if (r == NULL)
            return;

        Inorder(r->left);
        cout << r->data << "\t";
        Inorder(r->right);
    }

    void Postorder(Node* r) { // left -> right -> root
        if (r == NULL)
            return;
        Postorder(r->left);
        Postorder(r->right);
        cout << r->data << "\t";
    }

    Node* Search(Node* r, int key) {
        if (r == NULL)
            return NULL;
        else if (r->data == key)
            return r;
        else if (key < r->data)
            return Search(r->left, key);
        else
            return Search(r->right, key);
    }

    bool Search(int key) {
        Node* result = Search(root, key);

        if (result == NULL)
            return false;
        else
            return true;
    }

    Node* Findmin(Node* r) {
        if (r == NULL)
            return NULL;
        else if (r->left == NULL)
            return r;
        else
            return Findmin(r->left);
    }

    Node* Findmax(Node* r) {
        if (r == NULL)
            return NULL;
        else if (r->right == NULL)
            return r;
        else
            return Findmax(r->right);
    }

    Node* Delete(Node* r, int key) {
        if (r == NULL) // Empty Tree
            return NULL;

        if (key < r->data) // Item exists in left sub-tree
            r->left = Delete(r->left, key);
        else if (key > r->data) // Item exists in right sub-tree
            r->right = Delete(r->right, key);
        else {
            if (r->left == NULL && r->right == NULL) { // Leaf node
                delete r;
                r = NULL;
            }
            else if (r->left != NULL && r->right == NULL) { // One child on the left
                Node* temp = r;
                r = r->left;
                delete temp;
            }
            else if (r->left == NULL && r->right != NULL) { // One child on the right
                Node* temp = r;
                r = r->right;
                delete temp;
            }
            else { // Two children
                Node* max = Findmax(r->left);
                r->data = max->data;
                r->left = Delete(r->left, max->data);
            }
        }
        return r;
    }
};

int main() {
    // Insert nodes into the tree
    BST btree;
    btree.Insert(45);
    btree.Insert(15);
    btree.Insert(79);
    btree.Insert(90);
    btree.Insert(10);
    btree.Insert(55);
    btree.Insert(12);
    btree.Insert(20);
    btree.Insert(50);

    cout << "Display the Tree Content (Preorder):\n";
    btree.Preorder(btree.root);

    cout << "\n\nDelete Items\n";
    btree.root = btree.Delete(btree.root, 12);
    cout << "\nPreorder After Delete 12:\n";
    btree.Preorder(btree.root);

    btree.root = btree.Delete(btree.root, 15);
    cout << "\nPreorder After Delete 15:\n";
    btree.Preorder(btree.root);

    return 0;
}
