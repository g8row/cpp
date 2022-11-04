#include <iostream>

using namespace std;

int powOf10(int n){
    int powof10 = 1;
    for(int i = 0; i<n; i++){
         powof10*=10;
    }
    return powof10;
}

bool isLastDigitSmallest(int number){
    int lastDigit = number%10;
    number/=10;
    while (number>0){
        if(lastDigit>number%10){
            return false;
        }
        number/=10;
    }
    return true;
}

int sortDigit(int number){
    int sortedNumber = 0;
    int numberCopy = number;
    int count = 0;
    while(number>0){
        if(isLastDigitSmallest(numberCopy)){
            number -= numberCopy * powOf10(count);
            number += numberCopy/10 * powOf10(count);
            count = 0;
            sortedNumber*=10;
            sortedNumber+=numberCopy%10;
            numberCopy = number;
        }else{
            numberCopy/=10;
            count++;
        }
    }
    return sortedNumber;
}

int main(){
    cout << sortDigit(531261) << endl;
}