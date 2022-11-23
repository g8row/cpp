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

int subnum(int number, int n){
    int subnum = 0, powOf10=1;

    while(number>0){
        if(n%2 == 1){
            subnum += (number%10)*powOf10;
            powOf10*=10;
        }
        n/=2;
        number/=10;
    }
    return subnum;
}

bool contains (int number, int digit){
    int absNum = abs(number);
    while (absNum>0){
        if(digit == absNum%10){
            return true;
        }
        absNum/=10;
    }
    return false;
}

bool containsDiverseDigits(int number){
    while(number>10){
        int a = number%10;
        number/=10;
        if(contains(number,a)) return false;
    }
    return true;
}

int sumOfSubnums(int number){
    int length = lenOfInt(number);
    int numOfSubnums = pow(2, length);
    int sum = 0;

    for(int i=1; i<numOfSubnums;i++){
        int subn = subnum(number,i);
        if(containsDiverseDigits(subn)){
            cout << subn << " ";
            sum+=subn;
        }
    }
    cout << endl;
    return sum;
}

int main (){
    //001 010 
    int number;
    cin >> number;
    cout << sumOfSubnums(number);
}
