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
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    bool isEmpty() { return front == nullptr; }

    int dequeue() {
        if (!isEmpty()) {
            Node *temp = front;
            int data = temp->data;

            if (front == rear) {
                front = nullptr;
                rear = nullptr;
            } else {
                front = front->next;
            }

            delete temp;
            return data;
        } else {
            cout << "Queue is empty." << endl;
            return -1;
        }
    }

    void display() {
        if (isEmpty()) {
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
};

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
