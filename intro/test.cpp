#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char arr[100] = "1000";
    char ar2[100];

    strcpy(ar2, arr);
    cout << ar2;
}