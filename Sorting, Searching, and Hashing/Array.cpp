#include <algorithm>
#include <iostream>
using namespace std;

class Array {
  private:
    int *arr;
    int max;
    int size;

  public:
    Array(int size);
    ~Array();

    void insert(int value);
    void remove();
    void display();

    // Sorting Algorithms
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void mergeSort(int l, int r);
    void merge(int l, int m, int r);
    void quickSort();
    void heapSort();
    void radixSort();

    // Searching Algorithms
    int linearSearch(int value);
    int binarySearch(int value);
    int binarySearch(int value, int left, int right);
};

Array::Array(int size) {
    arr = new int[size];
    max = size;
    this->size = 0;
}

void Array::insert(int value) {
    if (size == max) {
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