#include <iostream>
using namespace std;

int main() {
    int n, i, target, choice, found = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements (enter in sorted order for Binary Search):" << endl;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value you want to search: ";
    cin >> target;

    cout << "\n--- SEARCH MENU ---" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        for (i = 0; i < n; i++) {
            if (arr[i] == target) {
                found = i;
                break;
            }
        }
    } 
    else if (choice == 2) {
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                found = mid;
                break;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    } 
    else {
        cout << "Invalid choice selection." << endl;
        return 0;
    }

    if (found != -1) {
        cout << "Element " << target << " found at index " << found << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}



