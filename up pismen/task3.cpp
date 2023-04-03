#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 1024;

int countLetters(char* str, char let) {
    int result = 0;
    while (*str) {
        if (*str == let)
            result++;
        str++;
    }
    return result;
}
int countDigits(int n) {
    int result = 0;
    while (n > 0) {
        result++;
        n /= 10;
    }
    return result;
}
void moveChars(char* str, int n) {
    int len = strlen(str);
    while (len >= 0) {
        *(str + len + n) = *(str + len);
        len--;
    }
}

bool convertToStrNumber(char* str) {
    int newSize = 0;
    int* hist = new int[26] {0};
    for (int i = 0;i < 26;i++) {
        hist[i] = countLetters(str, 'a' + i);
    }
    for (int i = 0;i < 26;i++) {
        newSize += hist[i] * countDigits(hist[i]);
    }
    if (newSize >= MAX_SIZE) {
        return 0;
    }

    while (*str) {
        if (!hist[*str - 'a']) {
            continue;
        }
        int digits = countDigits(hist[*str - 'a']);
        if (digits > 1) {
            moveChars(str + 1, digits - 1);
        }
        int histCopy = hist[*str - 'a'];
        for (int j = digits - 1;j >= 0;j--) {
            *(str + j) = (histCopy % 10) + '0';
            histCopy /= 10;
        }
        str += digits;
    }
    return 1;
}

int main() {
    char str[MAX_SIZE] = "aaabcaadcsmaabbbbsaaacc";
    cout << convertToStrNumber(str) << endl;
    cout << str << endl;
}