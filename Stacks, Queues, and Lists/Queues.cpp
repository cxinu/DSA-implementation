#include <iostream>
using namespace std;

const int MAX_SIZE = 4;

class Queue {
    int front;
    int rear;
    int arr[MAX_SIZE];

  public:
    Queue() { front = rear = -1; }
    void enqueue(int x);
    int dequeue();

    // ignore, only for checking output
    void display();
};

void Queue::enqueue(int x) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear++;
    arr[rear] = x;
    display();
}

int Queue::dequeue() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int removedItem = arr[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    display();
    return removedItem;
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
    q.enqueue(5);   // Queue is full can't Push

    q.dequeue();
    q.dequeue();
    q.enqueue(5);   // Queue is still full, because rear end is full

    q.dequeue();
    q.dequeue();
    q.dequeue();   // Queue is empty, now front and rear resets back to -1

    q.enqueue(5);   // Queue is reset, can push elements again
    q.enqueue(6);

    return 0;
}
