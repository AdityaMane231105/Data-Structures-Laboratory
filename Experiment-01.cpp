#include <iostream>
using namespace std;

void display(int arr[], int n) {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;
    int capacity = 10;

    cout << "--- Initial Array ---" << endl;
    display(arr, n);

    int pos = 2, newVal = 25;
    if (n < capacity) {
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = newVal;
        n++;
        cout << "\nAfter inserting " << newVal << " at index " << pos << ":" << endl;
        display(arr, n);
    }

    int delIdx = 3; 
    if (delIdx < n) {
        for (int i = delIdx; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        cout << "\nAfter deleting element at index " << delIdx << ":" << endl;
        display(arr, n);
    }

    int key = 40;
    int foundIdx = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            foundIdx = i;
            break;
        }
    }
    
    cout << "\nSearching for value " << key << "..." << endl;
    if (foundIdx != -1)
        cout << "Element found at index: " << foundIdx << endl;
    else
        cout << "Element not found." << endl;

    int updateIdx = 0;
    arr[updateIdx] = 100;
    cout << "\nAfter updating index 0 to 100:" << endl;
    display(arr, n);

    return 0;
}


