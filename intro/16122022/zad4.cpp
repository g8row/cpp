#include <iostream>
#include <cstring>
using namespace std;

void createHistogram(int hist[10], const char* str) {
    int len = strlen(str);
    char* ptrStart = new char[len + 1];
    char* iter = ptrStart;
    strcpy(ptrStart, str);
    for (int i = 0;i < len;i++) {
        hist[*ptrStart - '0']++;
        ptrStart++;
    }
    delete[] iter;
}

int countZeros(int* hist) {
    int zeros = 0;
    for (int i = 0; i < 10;i++) {
        if (hist[i] == 0) {
            zeros++;
        }
    }
    return zeros;
}

char* createResultStr(int* hist) {
    cout << countZeros(hist) << endl;
    char* result = new char[(10 - countZeros(hist)) * 3 + (10 - countZeros(hist))];
    char* beg = result;
    for (int i = 0; i < 10;i++) {
        if (hist[i] != 0) {
            *result = i + '0'; result++;
            *result = 'x'; result++;
            *result = hist[i] + '0'; result++;
            if (i != 9) {
                *result = ','; result++;
            }
        }
        else if (i == 9) {
            result--;
            *result = '\0';
        }
    }
    return beg;
}

int main() {
    char str[1024];
    cin >> str;
    int hist[10] = { 0 };
    createHistogram(hist, str);
    char* result = createResultStr(hist);
    cout << result << endl;
    delete[] result;
}