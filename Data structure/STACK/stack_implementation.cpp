#include <iostream>
#include <stack>//you can use this library in the data structure in the stack.
using namespace std;

// Define the structure for a node in the singly linked list
struct node {
    int data;       // Data part of the node
    node* next;     // Pointer to the next node in the list
};

// Initialize the top of the stack as NULL, indicating an empty stack
node* top = NULL;

// Function prototypes
void Display();     // Function to display all elements in the stack
void push(int value);  // Function to push an element onto the stack
int pop();          // Function to pop an element from the stack
int peek();         // Function to peek at the top element of the stack

int main() {
    // Push elements onto the stack
    push(5);
    push(10);
    push(15);
    push(20);
    push(30);
    push(40);
    
    // Display the stack
    Display();
    cout << endl;
    
    // Pop the top element from the stack
    pop();
    
    // Display the stack again after popping an element
    Display();
    cout << endl;
    
    // Peek at the top element of the stack
    cout << "Top element is: " << peek() << endl;

    return 0;
}

/**
 * Displays all the nodes in the stack from top to bottom.
 */
void Display() {
    if (top == NULL) { // Check if the stack is empty
        cout << "Stack underflow" << endl;
    } else {
        node* current_node;
        top = current_node; // Start with the top node
        // Traverse through the stack and print each node's data
        while (current_node != NULL) {
            cout << current_node->data << "\n";
            current_node = current_node->next; // Move to the next node
        }
    }
}

/**
 * Pushes a new value onto the stack.
 * @param value The value to be pushed onto the stack.
 */
void push(int value) {
    // Create a new node
    node* new_node = new node;
    new_node->data = value;    // Assign the value to the new node
    new_node->next = top;      // Point the new node's next to the current top
    top = new_node;            // Update the top to the new node
}

/**
 * Pops the top element from the stack.
 * @return The value of the popped element.
 */
int pop() {
    if (top == NULL) { // Check if the stack is empty
        cout << "Stack underflow" << endl;
        return -1;     // Return -1 if stack underflow occurred
    } else {
        node* first_node = top;  // Store the current top node
        top = top->next;         // Move top to the next node
        int value = first_node->data; // Get the data from the old top node
        delete first_node;       // Delete the old top node
        return value;            // Return the popped value
    }
}

/**
 * Peeks at the top element of the stack without removing it.
 * @return The value of the top element.
 */
int peek() {
    if (top == NULL) { // Check if the stack is empty
        cout << "Stack is empty" << endl;
        return -1;     // Return -1 if stack is empty
    } else {
        return top->data;   // Return the data of the top node
    }
}
