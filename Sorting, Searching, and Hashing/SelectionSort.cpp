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
    int nums[] = {3, 55, 6, 2, 6, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    Array arr(nums, n);
    arr.display();

    arr.selectionSort();
    arr.display();

    return 0;
}
