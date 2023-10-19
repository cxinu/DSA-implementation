#include "Array.cpp"

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high)
            i++;
        while (arr[j] > pivot && j > low)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void Array::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main() {
    int nums[] = {3, 55, 6, 2, 6, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    Array arr(nums, n);
    arr.display();

    arr.quickSort(0, n - 1);
    arr.display();

    return 0;
}
