#include "Array.cpp"

void Array::insertionSort() {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int nums[] = {3, 55, 6, 2, 6, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    Array arr(nums, n);
    arr.display();

    arr.insertionSort();
    arr.display();

    return 0;
}
