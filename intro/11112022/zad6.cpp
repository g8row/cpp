#include <iostream>

using namespace std;

const int MAX_SIZE = 1024;


bool isSorted(int arr[], size_t size){
    for(size_t i = 0; i < size-1; i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

int main() {
    int arr[MAX_SIZE];
    size_t size = 20;

    for(size_t i = 0; i < size; i++){
        cin >> arr[i];
    }
    
    cout << isSorted(arr, size) << endl;

    
}