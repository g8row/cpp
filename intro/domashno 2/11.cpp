#include <iostream>

using namespace std;

char toUpper(char a){
    return (a>='a' && a<='z') ? a - ('a'-'A') : '!';
}

int main() {
    cout << toUpper('1') << endl;
}