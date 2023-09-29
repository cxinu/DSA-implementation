#include <iostream>
using namespace std;

int const MAX_SIZE = 5;

class Stack {
    int top;
    int arr[MAX_SIZE];

  public:
    Stack() { top = -1; }
    void push(int value);
    int pop();

    void display();
};

void Stack::push(int value) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack is full" << endl;
        return;
    }

    top++;
    arr[top] = value;
}

int Stack::pop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    int temp = arr[top];
    top--;
    return temp;
}

// displays current state of array
void Stack::display() {
    cout << "Stack: ";

    if (top == -1) {
        cout << "Empty" << endl;
        return;
    }

    for (int i = 0; i <= top; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    Stack s;

    s.push(3);
    s.push(1);
    s.push(8);
    s.display();

    s.push(4);
    s.push(6);

    // stack full, can't push (9)
    s.push(9);
    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    // stack empty
    s.display();

    return 0;
}