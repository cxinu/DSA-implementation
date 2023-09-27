#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
};

class Queue {
  private:
    Node *front;
    Node *rear;

  public:
    Queue() { front = rear = nullptr; }

    void enqueue(int data);
    int dequeue();

    void display();
};

void Queue::enqueue(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (front == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    Node *temp = front;
    int data = temp->data;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
    }

    delete temp;
    return data;
}

void Queue::display() {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node *temp = front;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Queue elements: ";
    queue.display();

    cout << "Dequeued element: " << queue.dequeue() << endl;

    cout << "Queue elements after dequeue: ";
    queue.display();

    return 0;
}