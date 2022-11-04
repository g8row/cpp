#include <iostream>
#include <cmath>
using namespace std;

int main(){

    //зад1
    /* int sum = 0;

    for(int n;n!=0;){
        cin >> n;
        sum+=n;
    }
    
    cout << sum; */

    //зад2
    /*  int a, b;

    cin >> a >> b;

    for (int i = (a > b) ? b : a; i > 1; i--){
        if(a%i==0 && b%i==0){
            cout << i << " ";
        }
    }
    
    cout << 1; */

    //зад3
    
    /* int a;
    cin >> a;

    int lenOfInt = 1;
    bool isLenEven = false;

    for(int temp = a; (temp /= 10)!=0; lenOfInt++){} // намираме колко цифри има числото

    // if(lenOfInt % 2 != 0){
      //  cout << (int) (a / pow(10, lenOfInt/2+1)) * pow(10, lenOfInt/2) + (a % (int) pow(10, lenOfInt/2)) + 1; 
    //}

    int result = 0; // числото, което получаваме от преобразованията
    int powof10 = 10; // вместо pow функция, като започваме от най-дясната цифра, итерираме степента на 10, която ще ползваме

    if(lenOfInt%2==0){
        lenOfInt--; //  за да разглеждаме по-малко елементи
        isLenEven = true; // използва се по-нататък
    }

    for (int i = 1; i <= lenOfInt/2; i++)
    {
        result += ((a % powof10)/(powof10/10)) * (powof10/10);
        powof10*=10;
    }
    
    (isLenEven) ? powof10*=100 : powof10*=10; //  колко цифри ще пропуснем зависи от броя на цифрите
    
    for (int i = 1; i <= lenOfInt/2; i++)
    {
        result += ((a % powof10)/(powof10/10)) * (powof10/((isLenEven) ? 1000 : 100));
        powof10*=10;
    }

    cout << result << ", " << result+1;*/

    //zad4

    /* int a, b;
    cin >> a >> b;
    
    if(a==0 || a==1) a=2;
    for (int i = a; i <= b; i++){
        bool isPrime = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0 ){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            cout << i << " ";
        }
    } */

    //zad5
    /* int a;
    cin >> a;

    bool isPowof2 = true;

    while(a>1){
        if(a%2!=0){
            isPowof2 = false;
            break;
        }
        a/=2;
    }

    cout << isPowof2 << endl; */

    //zad6

    /* int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    for(int i = -100; i <= 100; i++){
        //cout << a*i*i*i*i + b*i*i*i + c*i*i + d*i + e;
        if(a*i*i*i*i + b*i*i*i + c*i*i + d*i + e >= 0){
            cout << i << ' ';
        }
    } */

    //zad8

    /* int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i ; j++){
            cout << "$ ";
        }
        cout << endl;
    } */

    // zad9
    /* int n;
    cin >> n;

    int spaces = n-1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < spaces; j++){
            cout << " ";
        }
        for(int j = i; j > 0; j--){
            cout << j;
        }
        cout << endl;
        spaces--;
    }
    spaces+=2;
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < spaces; j++){
            cout << " ";
        }
        for(int j = i; j > 0; j--){
            cout << j;
        }
        cout << endl;
        spaces++;
    } */
    // zad10

    /* int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(j%2==0){
                cout << 1 + j*n + i << " ";
            }else{
                cout << (j+1)*n - i << " ";
            }
        }
        cout << endl;
    } */

    //zad 11

    /* int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i%2==0){
                cout << 1 + i*n + j << " ";
            }else{
                cout << (i+1)*n - j << " ";
            }
        }
        cout << endl;
     } */

    //zad 12

    /* int n;
    cin >> n;

    cout << "+";
    for(int i = 0; i<n-2;i++){
        cout << "-";
    }
    cout << "+" << endl;

    for(int i = 0; i<n-2;i++){
        cout << "|";
        for(int j = 0; j<n-2;j++){
            cout << "-";
        }
        cout << "|" << endl;
    }
    cout << "+";
    for(int i = 0; i<n-2;i++){
        cout << "-";
    }
    cout << "+" << endl; */

    //zad 13
    /* int n;
    cin >> n;

    for(int i = 0; i<n;i++){
        cout << ".";
    }
    for(int i = 0; i<n-2;i++){
        cout << " ";
    }
    for(int i = 0; i<n;i++){
        cout << "." ;
    }
    cout << endl;

    for(int i = 0; i<(n-3)/2;i++){
        cout << ".";
        for(int i = 0; i<n-2;i++){
            cout << " ";
        }
        cout << ".";
        for(int i = 0; i<n-2;i++){
            cout << " ";
        }
        cout << ".";
        for(int i = 0; i<n-2;i++){
            cout << " ";
        }
        cout << "." << endl;
    }
    for(int i = 0; i<((n%2==0)?2:1);i++){
        cout << ".";
        for(int i = 0; i<n-2;i++){
            cout << " ";
        }
        for(int i = 0; i<n;i++){
            cout << ".";
        }
        for(int i = 0; i<n-2;i++){
            cout << " ";
        }
        cout << "." << endl;
    }
    for(int i = 0; i<(n-3)/2;i++){
        cout << ".";
        for(int i = 0; i<n-2;i++){
            cout << " ";
        }
        cout << ".";
        for(int i = 0; i<n-2;i++){
            cout << " ";
        }
        cout << ".";
        for(int i = 0; i<n-2;i++){
            cout << " ";
        }
        cout << "." << endl;
    }

    for(int i = 0; i<n;i++){
        cout << ".";
    }
    for(int i = 0; i<n-2;i++){
        cout << " ";
    }
    for(int i = 0; i<n;i++){
        cout << "." ;
    }
    cout << endl; */

    //zad 14

    /* int a;
    cin >> a;
    int spaces = a-1;
    for (int i = 1; i <= a; i++) {
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        for (int j = i-1; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
        spaces--;
    }
    spaces = a-1;
    for (int i = a-1; i > 0; i--) {
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        cout << i << endl;;
    } */

    //zad15

    /* int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            cout << j << " ";
        }

        for(int j = 0; j <= (n*3)--i*2; j++){
            cout << "  ";
        }

        for(int j = i; j >= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
    for(int i=1; i <= n; i++){
        cout << i << " ";
    }
    for(int i=1; i <= n; i++){
        cout << "- ";
    }
    for(int i=n; i >= 1; i--){
        cout << i << " ";
    }
    cout << endl;
    for(int i = n-1; i > 0; i--){
        for(int j = 1; j <= i; j++){
            cout << j << " ";
        }

        for(int j = 0; j <= (n*3)-1-i*2; j++){
            cout << "  ";
        }

        for(int j = i; j >= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    } */

    //zad 16
    /* int n;
    cin >> n;

    for(int i = 0; i <=n+1; i++){
        cout << "#";
    }
    cout << endl;

    for(int i = 1, digit = 0; i <=n; i++){
        cout << "#";
        for(int j = 1; j <= n; j++){
            digit++;
            if(digit>n){
                digit-=n;
            }
            cout << digit; 
        }
        cout << "#" << endl;
        digit++;
    }
    cout << "#";
    for(int i = 0; i < (n-1)/2;i++){
        cout << " ";
    }
    cout << ((n%2==0)? "XX" : "X");
    for(int i = 0; i < (n-1)/2;i++){
        cout << " ";
    }
    cout << "#" << endl;

    for(int i = 1, digit = n-1; i <=n; i++){
        cout << "#";
        for(int j = 1; j <= n; j++){
            digit++;
            if(digit>n){
                digit-=n;
            }
            cout << digit; 
        }
        cout << "#" << endl;
        digit--;
    }
    for(int i = 0; i <= n+1; i++){
        cout << "#";
    }
    cout << endl; */

    //zad 17

    /* int n;
    cin >> n;

    int biggest=0;
    int secBiggest=0;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        if(a>biggest){
            int buffer;
            buffer = biggest;
            biggest = a;
            secBiggest = buffer;
        }else if(a > secBiggest){
            secBiggest = a;
        }
    }
    cout << biggest << " " << secBiggest; */ 
}