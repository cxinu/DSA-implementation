#include <iostream>
using namespace std;

const int MAX_SIZE = 3;

class CircularQueue {
  private:
    int front;
    int rear;
    int arr[MAX_SIZE];

  public:
    CircularQueue() { front = rear = -1; }
    void enqueue(int x);
    int dequeue();

    // ignore, only for checking output
    void display();
};

void CircularQueue::enqueue(int x) {
    if ((rear + 1) % MAX_SIZE == front) {
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX_SIZE;
    arr[rear] = x;
    display();
}

int CircularQueue::dequeue() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int temp = arr[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
    display();
    return temp;
}

// displays current state of array
void CircularQueue::display() {
    cout << "CQueue: ";
    if (front == -1) {
        cout << "Empty" << endl;
        return;
    }
    int i;
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
        cout << arr[i] << " ";
    cout << arr[i] << endl;
}

int main() {
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);

    cq.dequeue();   // Circualr Queue No Issue after pop
    cq.enqueue(4);
    cq.enqueue(5);   // MAX memory usage, Queue is full

    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();

    return 0;
}
