#include <iostream>

using namespace std;

const int MAX_SIZE = 1024;

bool isPalindrome(int arr[], size_t size){
    
    for(size_t i = 0; i < (size/2); i++){
        if(arr[i]!=arr[size-1-i]){
            return false;
        }
    }
    return true;
}

int main() {
    int arr[MAX_SIZE];
    size_t size;

    cin >> size;

    for(size_t i = 0; i < size; i++){
        cin >> arr[i];
    }
    
    cout << isPalindrome(arr, size);
}