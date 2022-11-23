#include <iostream>
using namespace std;

const int SIZE = 32;

void toBinary(int k, bool arr[]){
    int mask = 1;
    for(int i = SIZE-1; i >=0; i--){
        arr[i] = (k & mask);
        k = k >> 1;
    }
}

void printArray(bool arr[]){
    for(int i = 0; i < SIZE; i++){
        cout << arr[i];
    }
    cout << endl;
}

int main(){
    int k;
    cin >> k;

    bool binary[SIZE];

    toBinary(k, binary);

    printArray(binary);
}