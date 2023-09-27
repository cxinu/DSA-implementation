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

    void insert_begin(int value);
    void insert_end(int value);
    void insert_pos(int value, int position);

    void delete_key(int key);
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
        std::cout << "Invalid position\n";
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
        std::cout << "Invalid position\n";
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
        std::cout << "Key not found\n";
        return;
    }

    if (current == start) {
        start = current->next;

        if (start != nullptr) {
            start->prev = nullptr;
        } else {
            end = nullptr;
        }

        delete current;

        return;
    }

    if (current == end) {
        end = current->prev;

        if (end != nullptr) {
            end->next = nullptr;
        } else {
            start = nullptr;
        }

        delete current;

        return;
    }

    current->prev->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}
