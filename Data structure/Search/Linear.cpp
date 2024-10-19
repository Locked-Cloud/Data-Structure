#include <iostream>
using namespace std;

// Function for Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) { // Check if the current element matches the target
            return i;  // Return the index of the target
        }
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    int arr[] = {2, 4, 0, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 1;

    int result = linearSearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
