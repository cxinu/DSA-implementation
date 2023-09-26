#include <iostream>

using namespace std;

// Define the Node struct
struct Node {
    int data;
    Node *next;
};

// Define the LinkedList class
class LinkedList {
  private:
    Node *head;

  public:
    LinkedList() { head = nullptr; }

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position);

    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(int position);

    void display();
};

// Insert a node at the beginning of the list
void LinkedList::insertAtBeginning(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert a node at the end of the list
void LinkedList::insertAtEnd(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Insert a node at a specific position in the list
void LinkedList::insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node *newNode = new Node;
    newNode->data = value;

    Node *current = head;
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Delete a node from the beginning of the list
void LinkedList::deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    delete temp;
}

// Delete a node from the end of the list
void LinkedList::deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *current = head;

    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;

    current->next = nullptr;
}

// Delete a node from a specific position in the list
void LinkedList::deleteFromPosition(int position) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node *current = head;

    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *temp = current->next;

    current->next = temp->next;

    delete temp;
}

// Display the contents of the list
void LinkedList::display() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    } else {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {

    LinkedList myList;

    myList.insertAtEnd(5);
    myList.insertAtEnd(10);
    myList.insertAtEnd(15);

    myList.display();

    myList.insertAtBeginning(0);
    myList.display();

    myList.insertAtPosition(7, 2);
    myList.display();

    myList.deleteFromBeginning();
    myList.display();

    myList.deleteFromEnd();
    myList.display();

    myList.deleteFromPosition(2);
    myList.display();

    myList.deleteFromPosition(10);

    return 0;
}
