#include "Array.cpp"

void merge(int arr[], int l, int m, int r) {
    int temp[r - l + 1];
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = l; i <= r; i++)
        arr[i] = temp[i - l];
}

void Array::mergeSort(int l, int r) {
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    merge(arr, l, mid, r);
}

int main() {
    int nums[] = {3, 55, 6, 2, 6, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    Array arr(nums, n);
    arr.display();

    arr.mergeSort(0, n - 1);
    arr.display();

    return 0;
}
