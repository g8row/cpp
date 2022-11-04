#include <iostream>

using namespace std;

int nthDigitInM(int m, int n) {
    for(int i=0;i<n;i++){
        m/=10;
    }
    return m%10;
}

int main() {
    cout << nthDigitInM(4321, 3) << endl;
}