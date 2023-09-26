#include <iostream>
using namespace std;

int const MAX_SIZE = 5;

class Deque {
  private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;   // current size

  public:
    Deque() {
        front = rear = -1;
        size = 0;
    };
    bool isEmpty();
    bool isFull();

    void pushFront(int x);
    void pushBack(int x);
    int popFront();
    int popBack();

    // ignore
    void display();
};

bool Deque::isEmpty() { return front == -1; }

bool Deque::isFull() {
    // IMPORTANT !!! this won't work in Deque, only works in Circular
    // return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);

    return size == MAX_SIZE;
}

void Deque::pushFront(int x) {
    if (isFull()) {
        cout << "Deque is full. Can't push to front." << endl;
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    arr[front] = x;
    size++;
    display();
}

void Deque::pushBack(int x) {
    if (isFull()) {
        cout << "Deque is full. Can't push to back." << endl;
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX_SIZE;
    arr[rear] = x;
    size++;
    display();
}

int Deque::popFront() {
    if (isEmpty()) {
        cout << "Deque is empty." << endl;
        return -1;
    }
    int removedItem = arr[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
    size--;
    display();
    return removedItem;
}

int Deque::popBack() {
    if (isEmpty()) {
        cout << "Deque is empty." << endl;
        return -1;
    }
    int removedItem = arr[rear];
    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    size--;
    display();
    return removedItem;
}

// Deque display function, current state
void Deque::display() {
    cout << "Deque: ";
    if (isEmpty()) {
        cout << "Empty" << endl;
        return;
    }
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    } else {
        for (int i = front; i < MAX_SIZE; i++)
            cout << arr[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Deque dq;

    dq.pushFront(1);
    dq.pushBack(2);
    dq.pushFront(3);
    dq.pushBack(4);
    dq.pushBack(5);

    dq.pushBack(9);
    dq.pushFront(3);

    dq.popBack();
    dq.popFront();

    return 0;
}
