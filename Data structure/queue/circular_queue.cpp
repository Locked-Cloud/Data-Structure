#include <iostream>
using namespace std;

#define size 5

int queue[size];
int front = -1;
int rear = -1;
bool isEmpty();
bool isFull();
void inqueue(int value);
void dequeue();
int peek();
void Display();
int main() {
    inqueue(5);
    inqueue(10);
    inqueue(15);
    inqueue(20);
    inqueue(25);
    inqueue(30);// full queue.
    Display();
    dequeue();
    Display();
    cout<<"the peek is : "<<peek()<<endl;
    inqueue(40);
    Display();
    dequeue();
    Display();
    cout<<"the peek is : "<<peek()<<endl;

    return 0;
}

bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(){
    if(front == 0 && rear == size - 1){
        return true;
    }
    else if(rear == front -1){
        return true;
    }else {
        return false;
    }
}

void inqueue(int value){
    if(isFull() ){
        cout<<"Queue is full. Cannot insert."<<endl;
        
    }else{
        if(isEmpty()) {
            front = rear = 0;
            queue[rear] = value;
        }else if (rear == size - 1)
        {
            rear = 0;
            queue[rear] = value;
        }else {
            rear++;
            queue[rear] = value;
        }
        
    
    }

}

void dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty. Cannot delete."<<endl;
        
    } else {
        if(front == rear){
            front = rear = -1;
        } else if(front == size - 1){
            front = 0;
        } else {
            front++;
        }
    }
}


int peek(){
    if(isEmpty()){
        cout<<"Queue is empty. Cannot peek."<<endl;
        return -1;
    } else {
        return queue[front];
    }
}

void Display(){
    if(isEmpty()){
        cout<<"Queue is empty. No elements to display."<<endl;
    }else {
        if(front <= rear){
            for(int i=front; i<=rear; i++){
                cout<<queue[i]<<"\t";
            }
            cout<<endl;
        }
        else {
            for(int i=front; i<size; i++){
                cout<<queue[i]<<"\t";
            }
            for(int i=0; i<=rear; i++){
                cout<<queue[i]<<"\t";
            }
            cout<<endl;
        }
    }
}
