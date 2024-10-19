#include <iostream>
using namespace std;

#define size 5
int stack[size], top = -1;

void push(int value);
int pop();
int peek();
void Display();
int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    cout << pop() << " popped from stack\n";
    cout << "Top element is " << peek() << endl;
    Display();
    return 0;
}

void push(int value) {
    if (top == size - 1) {
        cout << "Stack Overflow\n";
        return;
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed to stack\n";
    }
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1; // Returning a sentinel value to indicate underflow
    } else {
        return stack[top--];
    }
}

int peek() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1; // Returning a sentinel value to indicate underflow
    } else {
        return stack[top];
    }
}

void Display() {
    if (top == -1) {
        cout << "Stack Underflow\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}
