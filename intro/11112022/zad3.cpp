#include <iostream>

using namespace std;

const int MAX_SIZE = 1024;

void printArray(int arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void removeElementAtIndex(int arr[], size_t size, size_t index){
    for(size_t i = index; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    arr[size-1] = -1;
}

int main() {
    int arr[MAX_SIZE];
    size_t size;

    cin >> size;

    for(size_t i = 0; i < size; i++){
        cin >> arr[i];
    }

    size_t index;

    cin >> index;

    removeElementAtIndex(arr, size, index);

    printArray(arr, size);
}