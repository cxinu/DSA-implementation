#include "Array.cpp"

int Array::linearSearch(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

int main() {
    int nums[] = {3, 55, 6, 2, 6, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    Array arr(nums, n);
    arr.display();

    cout << arr.linearSearch(2) << endl;
    cout << arr.linearSearch(6) << endl;
    cout << arr.linearSearch(4) << endl;

    return 0;
}
