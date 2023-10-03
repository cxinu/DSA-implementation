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

    void insertFront(int x);
    void insertRear(int x);
    int deleteFront();
    int deleteRear();

    void display();
};

// Remove this for input restricted deque
void Deque::insertFront(int x) {
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

void Deque::insertRear(int x) {
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

int Deque::deleteFront() {
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
int Deque::deleteRear() {
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

    dq.insertFront(1);
    dq.insertRear(2);
    dq.insertFront(3);
    dq.insertRear(4);
    dq.insertRear(5);
    dq.display();

    dq.deleteRear();
    dq.deleteFront();
    dq.display();

    dq.insertRear(9);
    dq.insertFront(3);
    dq.display();

    return 0;
}
