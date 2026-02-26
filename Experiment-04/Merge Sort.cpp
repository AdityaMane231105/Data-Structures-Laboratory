#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int left, int mid, int right, int step, int n) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1&j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    cout << "After merge step " << step << ": ";
    printArray(arr, n);
}

void mergeSort(int arr[], int left, int right, int &step, int n) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, step, n);
        mergeSort(arr, mid + 1, right, step, n);
        step++;
        merge(arr, left, mid, right, step, n);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int step = 0;
    mergeSort(arr, 0, n - 1, step, n);

    cout << "Final sorted array: ";
    printArray(arr, n);

    return 0;
}


