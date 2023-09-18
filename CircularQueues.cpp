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

    // ignore
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
        front++;
    display();
    return temp;
}

void CircularQueue::display() {
    if (front == -1) {
        cout << "Empty Queue" << endl;
    } else {
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
            cout << arr[i] << " ";
        cout << arr[i] << endl;
    }
}

int main() {
    CircularQueue c;
    c.enqueue(1);
    c.enqueue(2);
    c.enqueue(3);
    c.enqueue(4);

    c.dequeue();
    c.dequeue();
    c.dequeue();
    c.dequeue();
}
