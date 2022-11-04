#include <iostream>

using namespace std;

int absValue(int number){
    return (number>0) ? number : -number;
}

int main() {
    cout << absValue(-5);
}