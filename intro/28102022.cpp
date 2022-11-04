#include <iostream>
#include <cmath>

using namespace std;

int sumInInterval(int n, int m){
    return (m*(m+1) - (n-1)*(n))/2;
}

int absoluteValue(int n){
    return (n>=0) ? n : -n;
}

double distOf2Points(int x, int y){
    return sqrt(x*x + y*y);
}

double sumOfTriangleSides(int ax, int ay, int bx, int by, int cx, int cy){
    return distOf2Points(ax, ay)+distOf2Points(bx, by)+distOf2Points(cx, cy);
}

double faceOfTriangle(int ax, int ay, int bx, int by, int cx, int cy){
    double a = distOf2Points(ax, ay);
    double b = distOf2Points(bx, by);
    double c = distOf2Points(cx, cy);
    double p = sumOfTriangleSides(ax, ay, bx, by, cx, cy)/2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}

bool isDigit(char a){
    return a>='1' && a<='9';
}

char toLower(char a){
    return (a>='A' && a<='Z') ? a + ('a'-'A') : '0';
}

char toUpper(char a){
    return (a>='a' && a<='z') ? a - ('a'-'A') : '0';
}

int toNumber(char a){
    return (a>='0' && a<='9') ? a -'0' : -1;
}

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


int main() {
    cout << sortDigit(1234321) << endl;   
}