#include "Array.cpp"

void Array::bubbleSort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    Array arr(7);
    arr.insert(48);
    arr.insert(28);
    arr.insert(34);
    arr.insert(89);
    arr.insert(29);
    arr.insert(93);
    arr.insert(19);

    arr.display();

    arr.bubbleSort();
    arr.display();

    return 0;
}
