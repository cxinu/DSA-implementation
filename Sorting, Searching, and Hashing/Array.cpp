#include <algorithm>
#include <iostream>
using namespace std;

class Array {
  private:
    int *arr;
    int MAX;
    int size;

  public:
    Array(int size);
    Array(int static_arr[], int size);
    ~Array();

    void insert(int value);
    void remove();
    void display();

    // Sorting Algorithms
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void mergeSort(int left, int right);
    void quickSort(int low, int high);
    void heapSort();
    void radixSort();

    // Searching Algorithms
    int linearSearch(int value);
    int binarySearch(int value);
    int binarySearch(int value, int left, int right);
};

Array::Array(int size) {
    MAX = size;
    this->size = 0;
    arr = new int[MAX];
}

Array::Array(int static_arr[], int size) {
    MAX = size;
    this->size = 0;
    arr = new int[MAX];
    for (int i = 0; i < MAX; i++) {
        arr[i] = static_arr[i];
        this->size++;
    }
}

void Array::insert(int value) {
    if (size == MAX) {
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