#include <iostream>

using namespace std;

const int MAX_SIZE = 1024;

void printArray(int arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printCounts(int arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        cout << i << ":" << arr[i] << " ";
    }
    cout << endl;
}

int count(int arr[], size_t size, int element){
    int count = 0;
    for(size_t i = 0; i < size; i++){
        if(arr[i] == element){
            count ++;
        }
    }
    return count;
}

void countAppearances (int arr[], size_t size, int counts[], size_t countsSize){
    for(size_t i = 0; i < countsSize; i++){
        counts[i] = count(arr, size, i);
    }
}

int main() {
    int arr[MAX_SIZE];
    size_t size = 20;


    for(size_t i = 0; i < size; i++){
        cin >> arr[i];
    }

    int counts[MAX_SIZE];
    size_t countsSize = 20;

    countAppearances(arr, size, counts, countsSize);

    printCounts(counts, countsSize);

}