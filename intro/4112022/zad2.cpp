#include <iostream>

using namespace std;

int calculateTriangleNumber(int n){
    int result = 0;
    for(int i = 1; i <= n; i++){
        result +=i;
    }
    return result;
}

void findLeftandRightNumbers(int number, int& leftNumber, int& rightNumber){
    int count = 1;
    rightNumber = 1;
    while(rightNumber<=number){
        count++;
        rightNumber=calculateTriangleNumber(count);
    }

    leftNumber = calculateTriangleNumber(count-1);
}

int main() {
	int number;
    cin >> number;

    int leftNumber = 0;
    int rightNumber = 0;

    findLeftandRightNumbers(number, leftNumber, rightNumber);

    cout << leftNumber << "+" << rightNumber  << "=" << leftNumber+rightNumber<< endl;
}