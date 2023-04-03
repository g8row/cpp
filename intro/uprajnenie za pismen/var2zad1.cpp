#include <iostream>
using namespace std;

bool isFibb(int n) {
    if (n == 0 || n == 1) {
        return true;
    }
    int fib1 = 1;
    int fib2 = 1;
    while (n >= fib2) {
        int buff = fib2 + fib1;
        if (n == buff) {
            return true;
        }
        fib1 = fib2;
        fib2 = buff;
    }
    return false;
}

int main() {
    cout << isFibb(12) << endl;
}