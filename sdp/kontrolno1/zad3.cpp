#include <iostream>
#include <string>
#include <stack>

bool calc(std::string expr) {
    std::stack<char> operands;
    std::stack<char> data;

    int currIndex = 0;
    while (currIndex < expr.size()) {
        if (expr[currIndex] == '!' || expr[currIndex] == '|' || expr[currIndex] == '&') {
            operands.push(expr[currIndex]);
            currIndex++;
        }
        else if (expr[currIndex] == '(') {
            data.push(expr[currIndex]);
            currIndex++;
        }
        else if (expr[currIndex] >= '0' && expr[currIndex] <= '9') {
            int number = expr[currIndex] - '0';
            currIndex++;
            while (expr[currIndex] >= '0' && expr[currIndex] <= '9') {
                number = number * 10 + expr[currIndex] - '0';
                currIndex++;
            }
            if (expr[currIndex] == ',') {
                currIndex++;
            }
            data.push((number % 2 == 0) ? 't' : 'f');
        }
        else if (expr[currIndex] == ')') {
            if (operands.top() == '!') {
                char res = (data.top() == 'f') ? 't' : 'f';
                data.pop();
                data.pop();
                data.push(res);
                operands.pop();
            }
            else if (operands.top() == '|') {
                bool beg = (data.top() == 'f') ? false : true;
                data.pop();
                while (data.top() != '(') {
                    beg = beg || ((data.top() == 'f') ? false : true);
                    data.pop();
                }
                data.pop();
                operands.pop();
                data.push((beg) ? 't' : 'f');
            }
            else if (operands.top() == '&') {
                bool beg = (data.top() == 'f') ? false : true;
                data.pop();
                while (data.top() != '(') {
                    beg = beg && ((data.top() == 'f') ? false : true);
                    data.pop();
                }
                data.pop();
                operands.pop();
                data.push((beg) ? 't' : 'f');
            }
            currIndex++;
        }
        else if (expr[currIndex] == ',') {
            currIndex++;
        }
    }
    return data.top() == 't';
}

int main() {
    std::string test("|(&(2,1,4),!(4))");
    std::cout << calc(test);
}