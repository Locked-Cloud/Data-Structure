#include <iostream>
using namespace std;
void swap (int &a ,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // n-1 is the index of the array
        bool flage = false;
        for (int j = 0; j < n - i - 1; j++) { // n - i - 1
        
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flage = true;
            }
        }
        if (!flage) break; // Stop if no elements were swapped
    }
}


void printArray(int arr[],int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    
    int arr[] = {22,44,1,12,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array without Bubble Sort : ";
    printArray(arr,n);
    bubbleSort(arr, n);
    cout<<endl;
    cout<<"Array after Bubble Sort : ";
    printArray(arr, n);
    
    return 0;

}