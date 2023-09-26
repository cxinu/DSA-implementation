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

    void push(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    bool isEmpty() { return top == nullptr; }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        } else {
            return top->data;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
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
};

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
