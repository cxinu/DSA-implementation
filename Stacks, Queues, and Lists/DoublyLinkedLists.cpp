#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList {
    Node *start;
    Node *end;

  public:
    DoublyLinkedList() { start = end = nullptr; }
    ~DoublyLinkedList() {
        while (start != nullptr) {
            Node *temp = start;
            start = start->next;
            delete temp;
        }
        end = nullptr;
    }

    void insert_begin(int value);
    void insert_end(int value);
    void insert_pos(int value, int position);

    void delete_key(int key);

    void display();
};

void DoublyLinkedList::insert_begin(int value) {
    Node *new_node = new Node();
    new_node->data = value;
    new_node->prev = nullptr;
    new_node->next = start;

    if (start != nullptr) {
        start->prev = new_node;
    } else {
        end = new_node;
    }

    start = new_node;
}

void DoublyLinkedList::insert_end(int value) {
    Node *new_node = new Node();
    new_node->data = value;
    new_node->prev = end;
    new_node->next = nullptr;

    if (end != nullptr) {
        end->next = new_node;
    } else {
        start = new_node;
    }

    end = new_node;
}

void DoublyLinkedList::insert_pos(int value, int position) {
    if (position < 1) {
        cout << "Invalid position\n";
        return;
    }

    if (position == 1) {
        insert_begin(value);
        return;
    }

    Node *current = start;

    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    Node *new_node = new Node();
    new_node->data = value;

    new_node->prev = current;
    new_node->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = new_node;
    } else {
        end = new_node;
    }

    current->next = new_node;
}

void DoublyLinkedList::delete_key(int key) {
    Node *current = start;

    while (current != nullptr && current->data != key) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Key not found\n";
        return;
    }

    if (start == end) {
        start = end = NULL;
    } else if (current == start) {
        start = current->next;
        start->prev = NULL;
    } else if (current == end) {
        end = current->prev;
        end->next = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
}

void DoublyLinkedList::display() {
    if (start == nullptr) {
        cout << "List is empty" << endl;
        return;
    } else {
        Node *temp = start;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    DoublyLinkedList list;

    list.insert_end(5);
    list.insert_end(15);
    list.display();

    list.insert_begin(0);
    list.display();

    list.insert_pos(9, 4);
    list.display();

    // delete key from middle
    list.delete_key(15);
    list.display();

    // delete key from start
    list.delete_key(0);
    list.display();

    // delete key from end
    list.delete_key(9);
    list.display();

    // delete key from signle node
    list.delete_key(5);
    list.display();
}