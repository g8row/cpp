#include <iostream>

using namespace std;

int main() {
    int varInt = 5;
    int* intPtr = &varInt;
    
    cout << *intPtr;
}