// Array.h

#ifndef ARRAY_H
#define ARRAY_H

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
    void mergSort();
    void quickSort();
    void heapSort();
    void radixSort();

    // Searching Algorithms
    int linearSearch(int value);
    int binarySearch(int value, int lower, int upper);
};

#endif   // ARRAY_H
