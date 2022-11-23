#include <iostream>
using namespace std;



int fromBinaryToDecimal(int n){
    int result = 0;
    int power = 1;
    while(n>0){
        result += (n%10)*power;
        power*=2;
        n/=10;
    }
    return result;
}

int main(){
    int k;
    cin >> k;
    if(k/10000000){
        
    }
    cout << fromBinaryToDecimal(k) << endl;
}