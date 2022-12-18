#include <iostream>
using namespace std;

const int MAX_N = 10000;
const int MAX_K = 1000;


void inputArr(int* arr, int n, int k) {
    for (int i = 0;i < n;i++) {
        cin >> *arr;
        while (*arr<0 || *arr>k) {
            cout << "Invalid input. Try again";
            cin >> *arr;
        }
        arr++;
    }
}

int* newHistogram(int* arr, int n, int k) {
    int* hist = new int[k] {0};
    for (int i = 0;i < n;i++) {
        hist[*arr]++;
        arr++;
    }
    return hist;
}

bool isPermutation(int* hist1, int* hist2, int k) {
    for (int i = 0;i < k;i++) {
        if (*hist1 != *hist2) {
            return false;
        }
        hist1++;
        hist2++;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    while (n<0 || n>MAX_N || k<0 || k>MAX_K) {
        cout << "Invalid input. Try again";
        cin >> n >> k;
    }

    int* arr1 = new int[n];
    int* arr2 = new int[n];

    inputArr(arr1, n, k);
    inputArr(arr2, n, k);

    int* hist1 = newHistogram(arr1, n, k);
    int* hist2 = newHistogram(arr2, n, k);

    cout << isPermutation(hist1, hist2, k);

    delete[] hist1;
    delete[] hist2;
}