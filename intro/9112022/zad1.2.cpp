#include <iostream>

using namespace std;

int lenOfInt(int a){
    int len = 1;
    while(a>9){
        len++;
        a/=10;
    }
    return len;
}

int powOf10(int n){
    int res = 1;
    for(int i = 0; i < n; i++){
        res*=10;
    }
    return res;
}

bool doABExist(int n, int k){\
    n/=10;
    int lenOfN = lenOfInt(n);
    int lenOfK = lenOfInt(k);
    while (lenOfN>lenOfK){
        if(n%powOf10(lenOfK) == k){
            return true;
        }
        n/=10;
        lenOfN--;
    }
    return false;
}

int main (){
    cout << doABExist(12034, 34) << endl;
}