#include <iostream>

using namespace std;

const int MAX_SIZE = 1024;

void printArray(int arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse(int arr[], size_t size){

    for(size_t i = 0; i < (size/2); i++){
        int buffer = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = buffer;
    }
}

void reverseFirstHalf(int arr[], size_t size){
    reverse(arr, (size+1)/2);
}

int main() {
    int arr[MAX_SIZE];
    size_t size;

    cin >> size;

    for(size_t i = 0; i < size; i++){
        cin >> arr[i];
    }

    reverseFirstHalf(arr, size);

    printArray(arr, size);
}