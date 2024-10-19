#include <iostream>
#include <vector>

using namespace std;
int main (){
    int arr[5] = {1, 2, 3, 4, 5};

    // Accessing array elements
    for (int i = 0; i < 5; i++) {
        cout << "Element at index " << i << ": " << arr[i] << endl;
    }

    return 0;

//////////////////////////////////////////////////////////////////////////////////////////

    vector<int> vec = {1, 2, 3, 4, 5};

    // Adding elements
    vec.push_back(6);

    // Accessing vector elements
    for (int i = 0; i < vec.size(); i++) {
        cout << "Element at index " << i << ": " << vec[i] << endl;
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

