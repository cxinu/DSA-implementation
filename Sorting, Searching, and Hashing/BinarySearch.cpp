#include "Array.cpp"

// non-recursive algorithm
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

// recursive algorithm
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

int main() {
    int size = 5;
    Array arr(size);

    arr.insert(0);
    arr.insert(2);
    arr.insert(3);
    arr.insert(5);
    arr.insert(6);

    arr.display();

    // non-recursive algorithm
    cout << arr.binarySearch(2) << endl;
    cout << arr.binarySearch(6) << endl;
    cout << arr.binarySearch(4) << endl;

    // recursive algorithm
    cout << arr.binarySearch(2, 0, size - 1) << endl;
    cout << arr.binarySearch(6, 0, size - 1) << endl;
    cout << arr.binarySearch(4, 0, size - 1) << endl;

    return 0;
}
