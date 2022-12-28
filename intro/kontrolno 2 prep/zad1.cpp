#include <iostream>
using namespace std;

bool containsSSum(const int* xs, int len, int s) {
    for (int i = 0;i < len - 1;i++) {
        for (int j = i;j < len;j++) {
            if (xs[i] + xs[j] == s) {
                return true;
            }
        }
    }
    return false;
}
//1 2 4 6

bool containsSSumSorted(const int* xs, int len, int s) {
    for (int i = 0;i < len - 1;i++) {
        if (s - xs[i] < xs[i]) {
            return false;
        }
        for (int j = i;j < len;j++) {
            if (xs[i] + xs[j] > s) {
                break;
            }
            if (xs[i] + xs[j] == s) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int len, s;
    cout << "input len of array: ";
    cin >> len;

    int* xs = new int[len];


    cout << "input array: ";

    for (int i = 0;i < len;i++) {
        cin >> xs[i];
    }

    cout << "input s: ";

    cin >> s;

    cout << containsSSum(xs, len, s) << endl;

    delete[] xs;
}