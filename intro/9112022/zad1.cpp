#include <iostream>

using namespace std;

bool doABExist (int n, int k){
    bool result = false;
    n/=10;
    int kcopy = k;
    //int digit = kcopy%10;
    while(n>9 && kcopy>0){
        int currN = n % 10;
        int currK = k % 10;
        if(currN == currK){
            result = true;
            n /= 10;
            k /= 10;
        }else{
            result = false;
            n /= 10;
            k = kcopy;
        }
    }
    return result;

}

bool validateInput(int n, int k){
    return n>0 && k>0;
}

int main (){
    int n, k;

    do{
        cin >> n >> k;
    }while(!validateInput(n,k));

    cout << doABExist(n, k) << endl;
}