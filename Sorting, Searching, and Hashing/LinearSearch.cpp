#include "Array.cpp"

int Array::linearSearch(int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

int main() {
    Array arr(5);

    arr.insert(0);
    arr.insert(2);
    arr.insert(3);
    arr.insert(5);
    arr.insert(6);

    arr.display();

    cout << arr.linearSearch(2) << endl;
    cout << arr.linearSearch(6) << endl;
    cout << arr.linearSearch(4) << endl;

    return 0;
}
