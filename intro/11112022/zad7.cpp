#include <iostream>

using namespace std;

const int MAX_SIZE = 1024;

void printArray(int arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void incrementBy1(int arr[], size_t size){
    int stillAdding = 1;
    for(int i = size-1; i>=0 && stillAdding; i--){
        arr[i]++;
        if(arr[i] == 10){
            arr[i] = 0;
        }else{
            stillAdding--;
        }
    }
    
}

int main() {
    int arr[MAX_SIZE];
    size_t size = 5;


    for(size_t i = 0; i < size; i++){
        cin >> arr[i];
    }
    incrementBy1(arr, size);
    printArray(arr, size);
}