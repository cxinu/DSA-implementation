#include <iostream>
using namespace std;

int const MAX_SIZE = 5;

class Deque {
  private:
    int front;
    int rear;
    int arr[MAX_SIZE];

  public:
    Deque() { front = rear = -1; };

    void pushFront(int x);
    void pushBack(int x);
    int popFront();
    int popBack();

    void display();
};

// Remove this for input restricted deque
void Deque::pushFront(int x) {
    if (front == 0) {
        cout << "Deque front is full" << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }

    arr[front] = x;
}

void Deque::pushBack(int x) {
    if (rear == MAX_SIZE - 1) {
        cout << "Deque back is full" << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    arr[rear] = x;
}

int Deque::popFront() {
    if (front == -1) {
        cout << "Deque is empty" << endl;
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

// Remove this for output restricted deque
int Deque::popBack() {
    if (front == -1) {
        cout << "Deque is empty." << endl;
        return -1;
    }

    int temp = arr[rear];

    if (front == rear)
        front = rear = -1;
    else {
        rear--;
    }

    return temp;
}

// Deque display function, current state
void Deque::display() {
    cout << "Deque: ";

    if (front == -1)
        cout << "Empty";

    for (int i = front; i <= rear && front != -1; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    Deque dq;

    dq.pushFront(1);
    dq.pushBack(2);
    dq.pushFront(3);
    dq.pushBack(4);
    dq.pushBack(5);
    dq.display();

    dq.popBack();
    dq.popFront();
    dq.display();

    dq.pushBack(9);
    dq.pushFront(3);
    dq.display();

    return 0;
}
