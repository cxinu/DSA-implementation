#include "Array.cpp"

// Using While loop
int Array::binarySearch(int value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

/*
// Using Recurssion
int Array::binarySearch(int value, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;

    if (arr[mid] == value) {
        return mid;
    } else if (arr[mid] > value) {
        return binarySearch(value, left, mid - 1);
    } else {
        return binarySearch(value, mid + 1, right);
    }
}

int Array::binarySearch(int value) { return binarySearch(value, 0, size - 1); }
 */

int main() {
    Array arr(5);

    arr.insert(0);
    arr.insert(2);
    arr.insert(3);
    arr.insert(5);
    arr.insert(6);

    arr.display();

    cout << arr.binarySearch(2) << endl;
    cout << arr.binarySearch(6) << endl;
    cout << arr.binarySearch(4) << endl;

    return 0;
}
