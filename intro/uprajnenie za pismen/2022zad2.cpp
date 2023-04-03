#include <iostream>
#include <cstring>
using namespace std;

char words[12][6] = {
    {"zero"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"},
    {"seven"}, {"eight"}, {"nine"}, {"plus"} , {"minus"}
};

char itoa(int i) {
    return i + '0';
}

int translateEq(char* input) {
    int result = 0;
    int currNum = 0;
    char* currStr = new char[6];
    char* currBeg = currStr;

    bool currFunction = 1; //1 adding, 0 subtracting

    while (*input != '\0') {
        *currStr = *input;
        currStr++;
        input++;
        for (int i = 0;i < 12;i++) {
            *currStr = '\0';
            if (!strcmp(currBeg, words[i])) {
                if (i < 10) { // chislo
                    currNum *= 10;
                    currNum += i;
                }
                else {
                    if (currFunction) {
                        result += currNum;
                        currNum = 0;
                    }
                    else {
                        result -= currNum;
                        currNum = 0;
                    }

                    if (i == 10) { // plus
                        currFunction = 1;
                    }
                    else { // minus
                        currFunction = 0;
                    }
                }
                currStr = currBeg;
                break;
            }
        }
        if (!*input) {
            if (currFunction) {
                result += currNum;
                currNum = 0;
            }
            else {
                result -= currNum;
                currNum = 0;
            }
        }
    }
    delete[] currBeg;
    return result;

}


int main() {
    char input[1024] = "oneminustwothreeplusfourfivesix";
    cout << translateEq(input) << endl;
}