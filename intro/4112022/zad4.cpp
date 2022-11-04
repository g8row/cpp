#include <iostream>

using namespace std;

int lenOfInt(int n){
    int len=0;
    while(n>0){
        n/=10;
        len++;
    }
    return len;
}

void count1sand0s(int num1, int num2, int& num1_1s, int& num1_0s,int& num2_1s,int& num2_0s){

}

int main() {
    int n;
    cin >> n;

    int num1, num2;
    cin >> num1 >> num2;

    if(lenOfInt(num1) > n || lenOfInt(num2) > n){
        return -1;
    }

    int num1_1s=0, num1_0s=0, num2_1s=0, num2_0s=0;

    count1sand0s(num1, num2, num1_1s, num1_0s, num2_1s, num2_0s);



}