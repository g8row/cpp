#include <iostream>
using namespace std;

const int SIZE = 32;

int shiftBit(int k, int bit){
    int mask =  (1 << bit);
    k = k ^ mask;
    return k;
}


int main(){
    int k, bit;
    cin >> k >> bit;

    cout << shiftBit(k, bit) << endl;
}
//111001110
//000001000
//111110111

// 1010
// 1000
// 1110