#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 1024;

int validInput(){
    int a;
    cin >> a;
    while(a<=0){
        cout << "Input valid length!" << endl;
        cin >> a;
    }
    return a;
}

void inputArray(int length, int arr[]){
    for(int i = 0; i < length; i++){
        cin >> arr[i];
    }
}

bool isPrime(int n){
    int sqr = sqrt(n);

    if(n == 0 || n == 1) return false;

    for(int i = 2; i <= sqr; i++){
        if(n%2 == 0){
            return false;
        }
    }
    return true;
}

void fillArrayWithIsPrime(int length, int arr[], bool primes[]){
    for(int i = 0; i <= length; i++){
        primes[arr[i]] = isPrime(arr[i]);
    }
}


bool isProblem(int i, int j, bool primes[]){
    bool isIPrime = primes[i];
    bool isJPrime = primes[j];

    if(!isIPrime && !isJPrime){
        return false;
    }else if(isIPrime && !isJPrime){
        return true;
    }else if (isIPrime && isJPrime){ 
        return i>j;
    }

    return false;
}

int countProblems(int length, int arr[], bool primes[]){
    int count = 0;
    for(int i = 0; i < length-1; i++){
        for(int j = i+1; j < length; j++){
            if(isProblem(arr[i], arr[j], primes)){
                count++;
            }
        }
    }
    return count;
}

int main (){

    int length = validInput();
    int arr[MAX_SIZE];
    bool primes[MAX_SIZE];

    inputArray(length, arr);

    fillArrayWithIsPrime(length, arr, primes);
        
    cout << countProblems(length, arr, primes) <<endl;
}