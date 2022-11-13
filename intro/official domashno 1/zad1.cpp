#include <iostream>

using namespace std;

int abs(int n){
    return (n>0) ? n : -n;
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

bool isSubset(int a, int b){
    int absA = abs(a);
    while(absA>0){
        if(!contains(b, absA%10)){
            return false;
        }
        absA/=10;
    }
    return true;
}

void strengthComparison(int first, int second){
    bool isFirstSubsetOfSecond = isSubset(first, second);
    bool isSecondSubsetOfFirst = isSubset(second, first);

    if(isFirstSubsetOfSecond && isSecondSubsetOfFirst){
        cout << "Equal strength" << endl;
        return;
    } else if(!isFirstSubsetOfSecond && isSecondSubsetOfFirst){
        cout << "Second is weaker" << endl;
        return;
    } else if(isFirstSubsetOfSecond && !isSecondSubsetOfFirst){
        cout << "First is weaker" << endl;
        return;
    } else {
        cout << "Not comparable" << endl;
        return;
    } 
}

int main (){
    int first, second;
    cin >> first >> second;

    strengthComparison(first, second);
}