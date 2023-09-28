#include "Array.h"
#include <iostream>
using namespace std;

Array::Array(int size) {
    arr = new int[size];
    max = size;
    this->size = 0;
}

void Array::insert(int value) {
    if (size == max - 1) {
        cout << "Array full" << endl;
        return;
    }
    arr[size] = value;
    size++;
}

void Array::remove() {
    if (size == 0) {
        cout << "Array empty" << endl;
        return;
    }
    arr[size] = -1;
    size--;
}

void Array::display() {
    if (size == 0) {
        cout << "Empty" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

Array::~Array() { delete[] arr; }