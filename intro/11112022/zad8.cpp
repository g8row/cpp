#include <iostream>

using namespace std;

const int MAX_SIZE = 4;

void printArray(bool arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void addArrays(bool arr[], bool arr2[], bool arr3[]){

    bool carryover = 0;

    for(int i = MAX_SIZE-1; i >= 0; i--){
        if(arr[i] && arr2[i]){
            arr3[i+1] = carryover;
            carryover = 1;
        }else if(!arr[i] && !arr2[i]){
            arr3[i+1] = carryover;
            carryover = 0;
        }else if(carryover){
            arr3[i+1] = 0;
        }else{
            arr3[i+1] = 1;
        }
    }
    
    arr3[0] = carryover;
}

int main() {
    bool arr[MAX_SIZE], arr2[MAX_SIZE];

    for(size_t i = 0; i < MAX_SIZE; i++){
        cin >> arr[i];
    }
    for(size_t i = 0; i < MAX_SIZE; i++){
        cin >> arr2[i];
    }

    bool arr3[MAX_SIZE+1];

    addArrays(arr, arr2, arr3);

    printArray(arr3, MAX_SIZE+1);
}