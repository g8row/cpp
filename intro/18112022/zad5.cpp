#include <iostream>
using namespace std;

const int SIZE = 32;

char getChar(int n){
    if(n >= 0 && n <= 9){
        return '0'+n;
    }
    if(n >= 10 && n <= 15){
        return 'A' + (n-10);
    }
    return 'X';
}

void fromDecimalToRandom(int num, int k, char arr[]){
    int pos = SIZE-1;
    while (num>0 && pos>=0){
        arr[pos] = getChar(num % k);
        num/=k;
        pos--;
    }
}


void printArray(char arr[]){
    for(int i = 0; i < SIZE; i++){
        cout << arr[i];
    }
    cout << endl;
}

void fill(char arr[]){
    for(int i = 0; i < SIZE; i++){
        arr[i] = '0';
    }
}

int main(){
    int num, k;
    cin >> num >> k;

    char arr[SIZE];
    fill(arr);
    fromDecimalToRandom(num, k, arr);
    printArray(arr);

    
}