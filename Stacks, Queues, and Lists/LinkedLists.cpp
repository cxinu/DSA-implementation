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
    ~LinkedList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert_begin(int value);
    void insert_end(int value);
    void insert_pos(int value, int position);

    void delete_begin();
    void delete_end();
    void delete_pos(int position);

    void display();
};

// Insert a node at the beginning of the list
void LinkedList::insert_begin(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert a node at the end of the list
void LinkedList::insert_end(int value) {
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

// Insert a node at a specific (xth) position in the list
void LinkedList::insert_pos(int value, int position) {
    Node *newNode = new Node;
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *prev_node = head;
    for (int i = 1; i < position - 1; i++) {
        prev_node = prev_node->next;
        if (prev_node == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
    }

    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

// Delete a node from the beginning of the list
void LinkedList::delete_begin() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    delete temp;
}

// Delete a node from the end of the list
void LinkedList::delete_end() {
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
void LinkedList::delete_pos(int position) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (position == 1) {
        Node *temp = head;
        head = temp->next;
        delete temp;
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

    myList.insert_end(5);
    myList.insert_end(10);
    myList.insert_end(15);

    myList.display();

    myList.insert_begin(0);
    myList.display();

    myList.insert_pos(7, 2);
    myList.display();

    myList.delete_begin();
    myList.display();

    myList.delete_end();
    myList.display();

    myList.delete_pos(2);
    myList.display();

    myList.delete_pos(10);

    return 0;
}
