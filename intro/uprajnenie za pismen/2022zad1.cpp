#include <iostream>
#include <cmath>
using namespace std;

bool isInputValid(char* input) {
    while (*input != '\0') {
        if (*input != 'y' && *input != 'g' && *input != 'r') {
            return 0;
        }
        input++;
    }
    return 1;
}
int steps(char* input) {
    int result = -1;
    bool skipping = false;
    while (*input != '\0')
    {
        if (!skipping) {
            result++;
            switch (*input)
            {
            case 'r':
                return result;
            case 'g':
                input++;
                if (*input == '\0') {
                    return result;
                }
                break;
            case 'y':
                skipping = true;
                break;
            }
        }
        else {
            if (*input == 'g') {
                skipping = false;
            }
            else {
                input++;
                if (*input == '\0') {
                    return result;
                }
            }
        }
    }
    return -1;
}

int maxSteps(char* input) {
    int result = 0;
    while (*input != '\0') {
        int currSteps = steps(input);
        if (currSteps > result) {
            result = currSteps;
        }
        input++;
    }
    return result;
}

int main() {
    char input[1025];
    cin >> input;
    if (!isInputValid(input)) {
        cout << "invalid input" << endl;
        return -1;
    }

    cout << maxSteps(input) << endl;

}