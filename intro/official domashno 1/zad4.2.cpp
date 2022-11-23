#include <iostream>
using namespace std;

int lenOfInt(int number){
    int count = 0;
    while(number>0){
        count++;
        number/=10;
    }
    return count;
}

int pow(int a, int n){
    int pow = 1;

    for(int i = 0; i < n; i++){
        pow*=a;
    }
    return pow;
}

int main (){
    //001 010 
    int number;
    cin >> number;
    int length = lenOfInt(number);
    int numOfSubnums = pow(2, length);

    for(int i=1; i<numOfSubnums;i++){
        int q = 0;
        while(i>length){
            i--;
            q++;
        }
        cout << number
    }
}
