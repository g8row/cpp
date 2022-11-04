#include <iostream>

using namespace std;

bool isUpper(char a){
    return a>='A' && a<='Z';
}

int main() {
    cout << isUpper('a') << endl;
}