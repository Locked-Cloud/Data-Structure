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