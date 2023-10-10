#include "Array.cpp"

void Array::selectionSort() {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min] > arr[j])
                min = j;
        }
        if (min != i)
            swap(arr[i], arr[min]);
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

    arr.selectionSort();
    arr.display();

    return 0;
}
