#include "Array.cpp"

void Array::insertionSort() {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i;
        while (j > 0 && temp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }
        if (arr[j] != temp)
            arr[j] = temp;
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

    arr.insertionSort();
    arr.display();

    return 0;
}
