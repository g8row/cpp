#include <iostream>

using namespace std;

bool isNumberMadeOfOneDigit(int number){
    while(number>9){
        int a = number % 10;
        number /= 10;
        int b = number % 10;

        if(b!=a){
            return false;
        }
    }

    return true;
}

int main() {
    cout << isNumberMadeOfOneDigit(21111111);
}