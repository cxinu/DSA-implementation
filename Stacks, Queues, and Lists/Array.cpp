#include <iostream>
using namespace std;

const int MAX = 100;

class Array {
  private:
    int arr[MAX];
    int size;

  public:
    Array(int n);
    void insert(int pos, int value);
    void remove(int pos);
    void display();
};

Array::Array(int n) {
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        arr[i] = element;
    }
    size = n;
}

void Array::insert(int pos, int value) {
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    size++;
}

void Array::remove(int pos) {
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void Array::display() {
    if (size == 0) {
        cout << "Empty" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, pos, val;

    // Initialization
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter elements of the array: ";
    Array arr(n);

    // Insertion
    cout << "Enter the position where you want to insert an element: ";
    cin >> pos;
    cout << "Enter the value to insert: ";
    cin >> val;
    arr.insert(pos, val);

    // Deletion
    cout << "Enter the position of the element to delete: ";
    cin >> pos;
    arr.remove(pos);

    // Display
    cout << "Array after operations is: ";
    arr.display();

    return 0;
}