#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number){
    for(int i = 2; i <= sqrt(number); i++){
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int countOfPrimeDividers(int number){
    int count = 0;
    for(int i = 2; i <= number; i++){
        if(number % i == 0 && isPrime(i)){
            count ++;
        }
    }
    return count;
}

int countOfNumbersWithKPrimeDivsInInterval(int a, int b, int k){
    int count = 0;
    for(int i = a; i <= b; i++){
        if (countOfPrimeDividers(i) == k){
            count++;
        }
    }
    return count;
}

int main() {
    cout << countOfNumbersWithKPrimeDivsInInterval(19, 42, 3) << endl;
}