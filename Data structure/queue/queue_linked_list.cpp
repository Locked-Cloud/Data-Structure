#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front =NULL;
Node* rear = NULL;

void inqueue(int value);
void dequeue();
int peek();
void Display();
int main() {
    inqueue(5);
    inqueue(10);
    inqueue(15);
    inqueue(20);
    inqueue(30);
    Display();
    cout << "Peek element is " << peek() << endl;
    Display();
    dequeue();
    Display();
    dequeue();
    Display();



    return 0;
}
void inqueue(int value){
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = new_node;
    }else{
        rear->next = new_node;
        rear = new_node;
        cout << "Inserted " << value << " into the queue." << endl;
    }
}

void dequeue(){
    if(front == NULL && rear == NULL){
        cout << "Queue is empty." << endl;
        return;
    }else if(front == rear){
        Node* ptr = front;
        front = rear = NULL;
        delete(ptr);
    }else{
        Node* ptr = front;
        front = front->next;
        delete(ptr);
    }
    
}
int peek(){
    if(front == NULL && rear == NULL){
        cout << "Queue is empty." << endl;
        return -1;
    } else{
        return front->data;
    }
}

void Display(){
    
    if(front == NULL && rear == NULL){
        cout << "Queue is empty." << endl;
        return;
    }
    Node* current = front;
    cout << "Queue elements are: ";
    while(current != NULL){
        cout << current->data << "\t";
        current = current->next;
    }
    cout << endl;
}


/////////////////////////////////////////////




#include <iostream>
using namespace std;

class Queue {
private:
    // Node structure for linked list
    struct Node {
        int data;
        Node* next;
    };

    Node* front; // Points to the front of the queue
    Node* rear;  // Points to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Destructor to clean up the allocated memory
    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        Node* new_node = new Node{value, NULL};
        if (front == NULL && rear == NULL) { // Queue is empty
            front = rear = new_node;
        } else { // Add to the end
            rear->next = new_node;
            rear = new_node;
        }
        cout << "Inserted " << value << " into the queue." << endl;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (front == NULL) { // Queue is empty
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) { // If the queue is now empty
            rear = NULL;
        }

        cout << "Removed " << temp->data << " from the queue." << endl;
        delete temp;
    }

    // Function to get the front element of the queue
    int peek() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    // Function to display all elements in the queue
    void display() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue elements are: ";
        while (current != NULL) {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    cout << "Peek element is " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
