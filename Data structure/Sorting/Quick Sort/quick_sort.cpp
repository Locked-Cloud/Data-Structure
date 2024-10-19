#include <iostream>
using namespace std;

// Swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {   // If the element is smaller than the pivot
            i++;
            swap(arr[i], arr[j]);  // Swap it with the element at i
        }
    }
    swap(arr[i + 1], arr[high]);   // Place the pivot in the correct position
    return i + 1;  // Return the pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array

        // Sort the elements before and after the pivot
        quickSort(arr, low, pi - 1);  // Left side
        quickSort(arr, pi + 1, high); // Right side
    }
}

// Print the array
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  // Sample array
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);  // Sort the array

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
