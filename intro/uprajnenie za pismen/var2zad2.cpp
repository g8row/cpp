#include <iostream>
using namespace std;

bool isFibb(int n) {
    if (n == 0 || n == 1) {
        return true;
    }
    int fib1 = 1;
    int fib2 = 1;
    while (n >= fib2) {
        int buff = fib2 + fib1;
        if (n == buff) {
            return true;
        }
        fib1 = fib2;
        fib2 = buff;
    }
    return false;
}
bool aboveSecondaryDiagonalConainsFibb(const int matrix[][4])
{
    for (size_t i = 0; i < 4; i++)
    {
        for (int j = 4 - 1; j > i; j--)
        {
            if (isFibb(matrix[i][j])) return true;
        }
    }
    return false;
}
int main() {
    int matrix[][4] =
    {
        {1, 4, 3, 4},
        {41, 42, 43, 44},
        {45, 46, 47, 48},
        {4, 4, 4, 4}
    };
    cout << aboveSecondaryDiagonalConainsFibb(matrix);
}