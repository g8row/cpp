#include <iostream>

using namespace std;

const int MAX_SIZE = 1024;

void printArray(int arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool contains(int arr[], size_t size, int element){
    for(size_t i = 0; i < size; i++){
        if(arr[i] == element){
            return true;
        }
    }
    return false;
}

int missingElement(int arr[], size_t size){
    for(int i = 0; i <= 20; i++){
        if(!contains(arr, size, i)){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    size_t size = 20;

    cin >> size;

    for(size_t i = 0; i < size; i++){
        cin >> arr[i];
    }
    //0 2 1 4 6 5 8 7 10 9 12 11 14 13 16 15 18 17 20 19
    cout << missingElement(arr, size) << endl;

    
}