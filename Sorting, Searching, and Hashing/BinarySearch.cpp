#include "Array.cpp"

int Array::binarySearch(int value, int lower, int upper) {
    if (lower > upper) {
        return -1;
    }

    int mid = (lower + upper) / 2;

    if (arr[mid] == value) {
        return mid;
    } else if (arr[mid] > value) {
        return binarySearch(value, lower, mid - 1);
    } else {
        return binarySearch(value, mid + 1, upper);
    }
}

int main() {
    Array arr(5);

    arr.insert(0);
    arr.insert(2);
    arr.insert(3);
    arr.insert(5);
    arr.insert(6);

    arr.display();

    cout << arr.binarySearch(2, 0, 4) << endl;
    cout << arr.binarySearch(6, 0, 4) << endl;
    cout << arr.binarySearch(4, 0, 4) << endl;

    return 0;
}
