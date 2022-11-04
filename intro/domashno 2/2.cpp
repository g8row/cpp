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

int main() {
    cout << digits(12341);
}