#include <iostream>
using namespace std;

const int N = 5;
const int matrix[N][N] = {
    {1,2,-3,5,-2},
    {-5,10,5,-2,1},
    {1,13,20,0,-3},
    {2,-7,5,10,3},
    {10,2,2,3,1}
};

bool equalRings(int& resultX, int& resultY) {
    int* ringsSums = new int[N / 2 + 1];
    int* ringsSumsBeg = ringsSums;
    for (int i = 0; i < (N / 2) + 1;i++) {
        for (int j = i;j < N - i;j++) {
            *ringsSums += matrix[i][j];
        }
        for (int j = i;j < N - i;j++) {
            *ringsSums += matrix[N - 1 - i][j];
        }
        for (int j = i + 1;j < N - i - 1;j++) {
            *ringsSums += matrix[j][i];
        }
        for (int j = i + 1;j < N - i - 1;j++) {
            *ringsSums += matrix[j][N - 1 - i];
        }
        ringsSums++;
    }
    *(ringsSums - 1) /= 2;
    ringsSums = ringsSumsBeg;
    int prevSum = *ringsSums;
    ringsSums++;
    for (int i = 1;i < N / 2 + 1;i++) {
        if (prevSum != *ringsSums) {
            resultX = resultY = i;
            delete[] ringsSumsBeg;
            return 0;
        }
        ringsSums++;
    }
    resultX = resultY = -1;
    delete[] ringsSumsBeg;
    return 1;
}

int main() {
    int x = 0, y = 0;
    equalRings(x, y);
    cout << x << y;
}