#include <iostream>
#include <cstring>
using namespace std;
//#pragma warning(disable:4996)


const int MAX_STR_LEN = 80;
const int LETTERS = 52;

bool isUpper(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

bool isLower(char ch) {
    return (ch >= 'a' && ch <= 'z');
}


bool* createHistogram(char* backpack) {
    bool* hist = new bool[LETTERS];
    for (int i = 0;i < LETTERS;i++) {
        hist[i] = 0;
    }
    for (int i = 0;i < LETTERS;i++) {
        if (isLower(*backpack)) {
            hist[*backpack - 'a'] = 1;
        }
        else if (isUpper(*backpack)) {
            hist[*backpack - 'A' + 26] = 1;
        }
        backpack++;
    }
    return hist;
}

char getIdentificator(char**& backpacks) {
    bool* hist1 = createHistogram(*backpacks);
    backpacks++;
    bool* hist2 = createHistogram(*backpacks);
    backpacks++;
    bool* hist3 = createHistogram(*backpacks);
    backpacks++;

    for (int i = 0;i < LETTERS;i++) {
        if (hist1[i] && hist2[i] && hist3[i]) {
            if (i < 26) {
                return 'a' + i;
            }
            else {
                return i - 26 + 'A';
            }
        }
    }
    return '\0';
    delete[] hist1;
    delete[] hist2;
    delete[] hist3;
}

char* getIdentificators(char** backpacks, int n) {
    int numberOfTeams = n / 3;
    char* result = new char[numberOfTeams];

    for (int i = 0;i < numberOfTeams;i++) {
        result[i] = getIdentificator(backpacks);
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

    char* identificators = getIdentificators(backpacks, n);

    for (int i = 0;i < n / 3;i++) {
        cout << identificators[i] << endl;
    }

    delete[]identificators;

    for (int i = 0;i < n;i++) {
        delete[] backpacks[i];
    }

    delete[] backpacks;
}