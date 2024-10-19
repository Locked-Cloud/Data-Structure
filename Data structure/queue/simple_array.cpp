#include <iostream>
using namespace std;

#define size 5
int queue[size];
int front = -1;
int rear = -1;

void enqueue(int value);
void dequeue();
int peek();
void Display();

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(30);
    Display();
    
    dequeue();
    Display();
    
    enqueue(35);
    Display();
    cout<<"peek is "<<peek()<<endl;

    return 0;
}

void enqueue(int value) {
    if(rear != size - 1) {
        if(front == -1 && rear == -1) {
            front++;
            rear++;
            queue[rear] = value;
            cout << value << " is inserted to the queue" << endl;
        } else {
            rear++;
            queue[rear] = value;
            cout << value << " is inserted to the queue" << endl;
        }
    } else {
        cout << "Queue is full" << endl;
    }
}

void dequeue() {
    if(front != -1 && rear != -1 && front <= rear) {
        cout << queue[front] << " is removed from the queue" << endl;
        front++;
        if (front > rear) {  // Queue becomes empty after dequeue
            front = -1;
            rear = -1;
        }
    } else {
        cout << "Queue is empty." << endl;
    }
}

int peek() {
    if(front != -1 && rear != -1 && front <= rear) {
        return queue[front];
    } else {
        cout << "Queue is empty." << endl;
        return -1;
    }
}

void Display() {
    if(front != -1 && rear != -1 && front <= rear) {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Queue is empty." << endl;
    }
}
