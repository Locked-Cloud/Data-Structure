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




/////////////////////////////////////////////



#include <iostream>
using namespace std;

#define SIZE 5 // Default initial size of the stack

class Stack {
private:
    int* stack;   // Array to store stack elements
    int top;      // Index of the top element
    int size;     // Current capacity of the stack

    void resize() {
        size *= 2;
        int* newStack = new int[size];
        for (int i = 0; i <= top; i++) {
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
        cout << "Stack resized to " << size << endl;
    }

public:
    Stack() { // Simplified constructor
        size = SIZE;
        stack = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] stack;
    }

    void push(int value) {
        if (top == size - 1) {
            resize();
        }
        stack[++top] = value;
        cout << value << " added to stack\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty, nothing to pop\n";
            return -1;
        }
        return stack[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return stack[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s; // Uses SIZE by default
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6); // Trigger resizing
    cout << s.pop() << " removed from stack\n";
    cout << "Top element: " << s.peek() << endl;
    s.display();
    return 0;
}
