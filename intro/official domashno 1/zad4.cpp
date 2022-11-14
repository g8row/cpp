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

int powOf10(int n){
    int pow = 1;

    for(int i = 0; i < n; i++){
        pow*=10;
    }
    return 10;
}

int addSubNums(int number){
    int length = lenOfInt(number);
    int numcopy = number;

    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            cout << number;
        }
    }
}

int main (){
    int number, result = 0;
    cin >> number;


}