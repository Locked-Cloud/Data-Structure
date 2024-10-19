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
