#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
};

class Stack {
  private:
    Node *top;

  public:
    Stack() { top = nullptr; }
    ~Stack() {
        while (top != nullptr) {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int data);
    void pop();

    int peek();
    void display();
};

void Stack::push(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
    } else {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

int Stack::peek() {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return -1;
    } else {
        return top->data;
    }
}

void Stack::display() {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node *temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Stack elements: ";
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    cout << "Stack elements after popping: ";
    stack.display();

    return 0;
}
