#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

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


int* getRepeatingCharsPriority(char* repeatingCharacters, int n) {
    int* result = new int[n];
    for (int i = 0;i < n;i++) {
        if (isLower(repeatingCharacters[i])) {
            result[i] = repeatingCharacters[i] - 'a' + 1;
        }
        else if (isUpper(repeatingCharacters[i])) {
            result[i] = repeatingCharacters[i] - 'A' + 26 + 1;
        }
    }
    return result;
}
int getPrioritySum(char** backpacks, int n) {
    char* repeatingChars = getRepeatingChars(backpacks, n);
    int* problemsPriority = getRepeatingCharsPriority(repeatingChars, n);

    int prioritySum = 0;

    for (int i = 0;i < n;i++) {
        prioritySum += problemsPriority[i];
    }

    delete[] problemsPriority;
    delete[] repeatingChars;
    return prioritySum;
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

    cout << getPrioritySum(backpacks, n);

    for (int i = 0;i < n;i++) {
        delete[] backpacks[i];
    }
    delete[] backpacks;
}