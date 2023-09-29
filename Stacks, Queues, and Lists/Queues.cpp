#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Queue {
    int front;
    int rear;
    int arr[MAX_SIZE];

  public:
    Queue() { front = rear = -1; }
    void enqueue(int x);
    int dequeue();

    void display();
};

void Queue::enqueue(int x) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue is full" << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    arr[rear] = x;
}

int Queue::dequeue() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    int temp = arr[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    return temp;
}

// displays current state of array
void Queue::display() {
    cout << "Queue: ";

    if (front == -1)
        cout << "Empty";

    for (int i = front; i <= rear && front != -1; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Queue is full
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    // Queue is still full, because rear end is full
    q.enqueue(5);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    // Queue is empty, now front = rear = -1
    q.display();

    // can push elements again
    q.enqueue(5);
    q.enqueue(6);
    q.display();

    return 0;
}
