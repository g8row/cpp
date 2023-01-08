#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

const int MAX_STR_LEN = 80;
const int LETTERS = 52;

bool isUpper(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

bool isLower(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

char checkBackpack(char* str) {
    int len = strlen(str);
    int firstLen = len / 2;
    char* firstComp = str;
    char* secondComp = str + firstLen;

    bool hist[LETTERS] = { 0 };

    for (int i = 0;i < firstLen;i++) {
        if (isLower(*firstComp)) {
            hist[*firstComp - 'a'] = 1;
        }
        else if (isUpper(*firstComp)) {
            hist[*firstComp - 'A' + 26] = 1;
        }
        firstComp++;
    }
    for (int i = 0;i < firstLen;i++) {
        if (isLower(*secondComp)) {
            if (hist[*secondComp - 'a']) {
                return *secondComp;
            }
        }
        else if (isUpper(*secondComp)) {
            if (hist[*secondComp - 'A' + 26]) {
                return *secondComp;
            }
        }
        secondComp++;
    }
    return '\0';
}

char* getRepeatingChars(char** backpacks, int n) {
    char* result = new char[n];
    for (int i = 0;i < n;i++) {
        result[i] = checkBackpack(backpacks[i]);
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    char** backpacks = new char* [n];

    for (int i = 0;i < n;i++) {
        backpacks[i] = new char[MAX_STR_LEN];
        cin >> backpacks[i];
        if (strlen(backpacks[i]) % 2) {
            cout << "Spisuka e greshen" << endl;
            return -1;
        }
    }

    char* repeatingChars = getRepeatingChars(backpacks, n);

    for (int i = 0;i < n;i++) {
        cout << repeatingChars[i] << endl;
    }

    delete[] repeatingChars;

    for (int i = 0;i < n;i++) {
        delete[] backpacks[i];
    }
    delete[] backpacks;
}