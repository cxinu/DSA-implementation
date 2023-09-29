#include <iostream>
using namespace std;

int const MAX_SIZE = 4;

struct item {
    int data;
    int p_no;
};

class PriorityQueue {
    int front;
    int rear;
    item arr[MAX_SIZE];

  public:
    PriorityQueue() { front = rear = -1; }

    void enqueue(int x, int p);
    int dequeue();
    void sort();

    void display();
};

void PriorityQueue::enqueue(int x, int p) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue is full" << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    item newItem;
    newItem.data = x;
    newItem.p_no = p;
    arr[rear] = newItem;

    sort();
}

int PriorityQueue::dequeue() {
    if (front == -1) {
        return -1;
    }

    int temp = arr[front].data;

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    return temp;
}

// Bubble sort
void PriorityQueue::sort() {
    for (int i = front; i < rear; i++) {
        for (int j = 0; j < rear - i; j++) {
            if (arr[j].p_no > arr[j + 1].p_no) {
                // swap arr[j] and arr[j + 1]
                item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// displays current state of array
void PriorityQueue::display() {
    cout << "PQueue: ";
    if (front == -1) {
        cout << "Empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++)
        cout << arr[i].data << "-" << arr[i].p_no << " ";
    cout << endl;
}

int main() {
    PriorityQueue pq;
    pq.enqueue(50, 3);
    pq.enqueue(34, 7);
    pq.enqueue(89, 2);
    pq.enqueue(42, 8);
    pq.enqueue(69, 1);

    // Sorted in priority order
    pq.display();

    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;

    // Items popped in priority order
    pq.display();

    return 0;
}