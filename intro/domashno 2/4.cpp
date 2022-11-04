#include <iostream>

using namespace std;

int digits(int number){
    int count = 0;
    while (number>0){
        number/=10;
        count++;
    }
    return count;
}

int powOf10(int n){
    int pow = 1;

    for(int i = 0; i < n; i++){
        pow*=10;
    }
    return pow;
}

int concatenate (int a, int b){
    return a*powOf10(digits(b)) + b;
}
int main() {
    cout << concatenate(191, 2321) << endl;
}