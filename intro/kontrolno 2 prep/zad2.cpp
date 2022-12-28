#include <iostream>
using namespace std;

int strleng(const char* str) {
    int len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}


void findLongestWord(const char* str, int& biggestLen, int& endInd) {
    int len = strleng(str);
    int currentLen = 0;

    for (int i = 0;i < len + 1;i++) {
        if (str[i] != ' ') {
            currentLen++;
        }
        else {
            if (currentLen > biggestLen) {
                endInd = i;
                biggestLen = currentLen;
            }
            currentLen = 0;
        }
    }
}
void copyLongestWord(const char* str, char* result, int len, int endInd) {
    for (int i = endInd - len;i < endInd;i++) {
        *result = str[i];
        result++;
    }
    *result = '\0';
}

int main() {
    const char* str = "sssss ss s s  sss ssss8ss ss s ";
    int endInd = 0, biggestLen = 0;
    findLongestWord(str, biggestLen, endInd);
    char* result = new char[biggestLen + 1];

    copyLongestWord(str, result, biggestLen, endInd);

    cout << result << endl;
    result = longestWord(str);
    cout << result << endl;

    delete[] result;
}