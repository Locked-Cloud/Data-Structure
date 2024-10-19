#include <iostream>
using namespace std;

// Function for Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Find the middle element

        if (arr[mid] == target) {
            return mid;  // Target found at index mid
        }

        if (arr[mid] < target) {
            low = mid + 1;  // Target is in the right half
        } else {
            high = mid - 1;  // Target is in the left half
        }
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};  // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
