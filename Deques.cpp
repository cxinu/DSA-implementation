#include <iostream>
using namespace std;

class Deque {
  private:
    int *arr;
    int front;
    int rear;
    int capacity;

  public:
    Deque(int size);
    ~Deque();
    bool isEmpty();
    bool isFull();
    void pushFront(int x);
    void pushBack(int x);
    int popFront();
    int popBack();
};

Deque::Deque(int size) {
    capacity = size;
    arr = new int[capacity];
    front = -1;
    rear = -1;
}

Deque::~Deque() { delete[] arr; }

bool Deque::isEmpty() { return front == -1; }

bool Deque::isFull() {
    return (front == 0 && rear == capacity - 1) || (front == rear + 1);
}

void Deque::pushFront(int x) {
    if (isFull()) {
        cout << "Deque is full. Cannot push to front." << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = capacity - 1;
    } else {
        front--;
    }

    arr[front] = x;
}

void Deque::pushBack(int x) {
    if (isFull()) {
        cout << "Deque is full. Cannot push to back." << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == capacity - 1) {
        rear = 0;
    } else {
        rear++;
    }

    arr[rear] = x;
}

int Deque::popFront() {
    if (isEmpty()) {
        cout << "Deque is empty. Cannot pop from front." << endl;
        return -1;   // Return a sentinel value for an empty deque
    }

    int removedItem = arr[front];

    if (front == rear) {
        front = rear =
            -1;   // Reset the deque if it becomes empty after this pop
    } else if (front == capacity - 1) {
        front = 0;
    } else {
        front++;
    }

    return removedItem;
}

int Deque::popBack() {
    if (isEmpty()) {
        cout << "Deque is empty. Cannot pop from back." << endl;
        return -1;   // Return a sentinel value for an empty deque
    }

    int removedItem = arr[rear];

    if (front == rear) {
        front = rear =
            -1;   // Reset the deque if it becomes empty after this pop
    } else if (rear == 0) {
        rear = capacity - 1;
    } else {
        rear--;
    }

    return removedItem;
}

int main() {
    Deque dq(5);   // Create a deque with a maximum capacity of 5

    dq.pushFront(1);
    dq.pushBack(2);
    dq.pushFront(3);
    dq.pushBack(4);

    cout << "Popped from front: " << dq.popFront() << endl;
    cout << "Popped from back: " << dq.popBack() << endl;

    return 0;
}
