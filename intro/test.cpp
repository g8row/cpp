#include <iostream>

using namespace std;

int main() {
    int x=10, y=10;

    y=x=x++;

    cout << x << " " << y << endl;
}