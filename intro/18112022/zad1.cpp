#include <iostream>
using namespace std;

int powOf2(int k){
    int res = 0;
    while(k>1){
        k = k >> 1;
        res++;
    }
    return res;
}

int main(){
    int k;
    cin >> k;

    cout << powOf2(k) << endl;
}