#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int trg = arr[i];  // Element to be positioned
        int j = i - 1; //0 in the index of the array

        // Shift elements that are greater than trg to the right
        while (j >= 0 && arr[j] > trg) {
            arr[j + 1] = arr[j]; // Move the element one position to the right
            j--;
        }
        arr[j + 1] = trg; // Place trg in its correct position
    }
}

// Function to print the array
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n); // Sort the array

    cout << "Sorted array: ";
    printArray(arr, n); // Print the sorted array

    return 0;
}
