#include <iostream>
using namespace std;

void concatNumbers(short(*digits)[4], int* numbers)
{
    for (size_t i = 0; i < 5; i++)
    {
        int stepenIliKotETamNaAngliiski = 1;
        for (int j = 4 - 1; j >= 0; j--)
        {
            numbers[i] += digits[i][j] * stepenIliKotETamNaAngliiski;
            stepenIliKotETamNaAngliiski *= 10;
        }
    }
}
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    short digits[5][4] =
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,0,1,2},
        {3,4,5,6},
        {7,8,9,0}
    };
    int numbers[5] = { 0 };
    concatNumbers(digits, numbers);
    printArray(numbers, 5);

    char str[] = "\n\"\\BB ";
    cout << sizeof(str);

    return 0;
}