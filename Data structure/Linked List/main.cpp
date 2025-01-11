#include <iostream>
using namespace std;

// Define the structure for a node in the singly linked list
struct node{
    int data;       // Data part of the node
    node* next;     // Pointer to the next node
};

// Initialize the head of the list as NULL, indicating an empty list
node* head  = NULL;

// Function prototypes
void insertnode(int value);
void Display();
void Delete(int value);
void insert_beg(int value);
void Delete_beg();
void Delete_end();


int main(){
    // Insert nodes at the end of the list
    insertnode(10);
    insertnode(20);
    insertnode(30);

    // Display the current list
    Display();
    cout << endl;

    // Delete a node with value 10
    Delete(10);
    cout << endl;

    // Display the list after deletion
    Display();
    cout << endl;

    // Insert a node at the beginning with value 5
    insert_beg(5);
    Display();
    cout << endl;

    // Delete the first node
    Delete_beg();
    Display();
    cout << endl;

    // Delete the last node
    Delete_end();    
    Display();
    cout << endl;

    return 0;
}

/**
 * Inserts a new node with the given value at the end of the list.
 * @param value The data value to be inserted into the new node.
 */
void insertnode(int value){
    node* new_node = new node; // Create a new node
    new_node->data = value;    // Assign data to the new node
    new_node->next = NULL;     // Initialize the next pointer as NULL

    if(head == NULL){
        // If the list is empty, make the new node as head
        head = new_node;
    } else {
        node* last = head;
        // Traverse to the end of the list
        while (last->next != NULL){   
            last = last->next;
        }
        // Link the new node at the end
        last->next = new_node;
    }
}

/**
 * Displays all the nodes in the list.
 */
void Display(){
    if(head == NULL){
        cout << "The list is empty." << endl;
    } else {
        node* current_node = head;
        // Traverse through the list and print each node's data
        while (current_node != NULL){
            cout << current_node->data << "\t";
            current_node = current_node->next;
        }
    }
}

/**
 * Deletes the first occurrence of a node with the specified value.
 * @param value The data value of the node to be deleted.
 */
void Delete(int value){
    if(head == NULL){
        cout << "The list is empty." << endl;
        return;
    }

    node* current = head;
    node* previous = NULL;

    // Check if the head node holds the value to be deleted
    if(current->data == value){
        head = current->next;  // Move head to the next node
        delete current;        // Delete the old head node
        return;
    }

    // Traverse the list to find the node to delete
    while(current != NULL && current->data != value){
        previous = current;
        current = current->next;
    }

    if(current == NULL){
        // Value not found in the list
        cout << "The value is not in the list." << endl;
        return;
    }

    // Unlink the node from the list and delete it
    previous->next = current->next;
    delete current;
}

/**
 * Inserts a new node with the given value at the beginning of the list.
 * @param value The data value to be inserted into the new node.
 */
void insert_beg(int value){
    node* new_node = new node; // Create a new node
    new_node->data = value;    // Assign data to the new node
    new_node->next = head;     // Point new node's next to current head
    head = new_node;           // Update head to the new node
}

/**
 * Deletes the first node of the list.
 */
void Delete_beg(){
    if(head == NULL){
        cout << "The list is empty." << endl;
    } else {
        node* first_node = head;    // Store current head
        head = head->next;          // Move head to the next node
        delete first_node;          // Delete the old head node
    }
}

/**
 * Deletes the last node of the list.
 */
void Delete_end(){
    if (head == NULL) {
        cout << "The list is empty." << endl;
    } else if (head->next == NULL) {
        // If there's only one node in the list
        delete head;    // Delete the single node
        head = NULL;    // Update head to NULL
    } else {
        node* ptr = head;
        // Traverse to the second last node
        while (ptr->next->next != NULL) {
            ptr = ptr->next;
        }
        // Delete the last node and update second last node's next to NULL
        delete ptr->next;
        ptr->next = NULL;
    }
}


/////////////////////////////////////////////



#include <iostream>
using namespace std;

struct Node {
    int item;
    Node *next;
};

class LinkedList {
private:
    Node *head;
    
public:
    // Constructor to initialize the list
    LinkedList() {
        head = NULL;
    }

    // Insert a node at the beginning of the list
    void insert_first(Node d) {
        Node *ptr = new Node;
        *ptr = d;
        ptr->next = head;
        head = ptr;
    }

    // Insert a node at the end of the list
    void insert_last(Node d) {
        if (head == NULL) {
            insert_first(d);
            return;
        }
        Node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new Node;
        ptr = ptr->next;
        *ptr = d;
        ptr->next = NULL;
    }

    // Insert an item in order
    void insert_item_order(Node d) {
        if (head == NULL || d.item < head->item) {
            insert_first(d);
            return;
        }
        Node *ptr = head;
        while (ptr->next != NULL && ptr->next->item < d.item) {
            ptr = ptr->next;
        }
        Node *temp = new Node;
        *temp = d;
        temp->next = ptr->next;
        ptr->next = temp;
    }

    // Insert an item at a specific index
    void insert_index(Node d, int n) {
        if (n == 0 || head == NULL) {
            insert_first(d);
            return;
        }
        Node *ptr = head;
        for (int k = 0; k < n && ptr->next != NULL; k++) {
            ptr = ptr->next;
        }
        Node *temp = new Node;
        *temp = d;
        temp->next = ptr->next;
        ptr->next = temp;
    }

    // Check if the list is empty
    bool is_empty() {
        return (head == NULL);
    }

    // Get the first element of the list
    Node read_first() {
        return *head;
    }

    // Count the number of nodes in the list
    int number_of_nodes() {
        int counter = 0;
        Node *ptr = head;
        while (ptr != NULL) {
            counter++;
            ptr = ptr->next;
        }
        return counter;
    }

    // Get the last element of the list
    Node read_last() {
        Node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        return *ptr;
    }

    // Get data of a node by index
    Node get_index_data(int index) {
        Node *ptr = head;
        for (int k = 0; k < index && ptr != NULL; k++) {
            ptr = ptr->next;
        }
        return *ptr;
    }

    // Get data of a node by item
    Node get_item_data(int item) {
        Node *ptr = head;
        while (ptr != NULL) {
            if (ptr->item == item) {
                return *ptr;
            }
            ptr = ptr->next;
        }
        Node temp;
        temp.item = 0;
        temp.next = NULL;
        return temp;
    }

    // Delete the first element of the list
    void delete_first() {
        if (head != NULL) {
            Node *ptr = head;
            head = head->next;
            delete ptr;
        }
    }

    // Delete the last element of the list
    void delete_last() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete_first();
            return;
        }
        Node *ptr = head;
        while (ptr->next->next != NULL) {
            ptr = ptr->next;
        }
        Node *temp = ptr->next;
        ptr->next = NULL;
        delete temp;
    }

    // Print all nodes in the list
    void print_list() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list1;
    Node temp;
    cout << "Enter 5 numbers: ";
    
    // Input 5 numbers and insert them at the beginning of the list
    for (int k = 0; k < 5; k++) {
        cin >> temp.item;
        temp.next = NULL;
        list1.insert_first(temp);
    }
    
    // Delete the last element and display the list
    list1.delete_last();
    
    cout << "Data in Linked List: ";
    list1.print_list();

    // Search for an item
    int x;
    cin >> x;
    temp = list1.get_item_data(x);
    cout << "Found item: " << temp.item << endl;
}
