#include <iostream>
using namespace std;

int rowSum(int** arr, int index, int n) {
    int sum = 0;
    for (int j = 0;j < n;j++) {
        sum += arr[index][j];
    }
    return sum;
}

int indexOfBiggestRowSum(int** const arr, int n, int m) {
    int biggestSum = rowSum(arr, 0, n);
    int rowIndex = 0;
    for (int i = 1;i < m;i++) {
        int tempSum = rowSum(arr, i, n);
        if (biggestSum < tempSum) {
            biggestSum = tempSum;
            rowIndex = i;
        }
    }
    return rowIndex;
}

int main() {
    int n, m;
    cin >> n >> m;

    int** arr = new int* [m];
    for (int i = 0;i < m;i++) {
        arr[i] = new int[n];
    }

    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }

    cout << indexOfBiggestRowSum(arr, n, m);

    for (int i = 0;i < m;i++) {
        delete[] arr[i];
    }
    delete[] arr;
}