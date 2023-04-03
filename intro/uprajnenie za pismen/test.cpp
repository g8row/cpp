#include <iostream>
using namespace std;

int main() {
    int res = 0;
    for (int i = 1;i <= 360;i++) {
        if (!(i % 2) || !(i % 3) || !(i % 5)) {
            res++;
        }
    }
    cout << res;
}