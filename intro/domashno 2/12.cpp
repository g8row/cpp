#include <iostream>

using namespace std;

int toNumber(char a){
    return (a>='0' && a<='9') ? a -'0' : -1;
}

int main() {
    cout << toNumber('!') << endl;
}