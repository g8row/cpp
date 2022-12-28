#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int rows = 5, columns = 8;




bool isLowest(char ch) {
    return ch == 'a' || ch == 'S';
}
bool isHighest(char ch) {
    return ch == 'z' || ch == 'E';
}
bool isValidMove(char ch1, char ch2) {
    return ch2 == (ch1 + 1) || ch1 == ch2 || (isHighest(ch1) && isHighest(ch2)) || (isLowest(ch1) && isLowest(ch2));
}

void path(int x, int y, int& shortestPathLen, int currPathLen, char matrix[rows][columns], bool walked[rows][columns]) {

    currPathLen++;

    walked[x][y] = 1;
    if (matrix[x][y] == 'E') {
        if (currPathLen < shortestPathLen) {
            shortestPathLen = currPathLen;
        }
        walked[x][y] = 0;
        return;
    }

    if (x - 1 > -1) {
        if (!walked[x - 1][y] && isValidMove(matrix[x][y], matrix[x - 1][y])) {
            path(x - 1, y, shortestPathLen, currPathLen, matrix, walked);
        }
    }
    if (x + 1 < rows) {
        if (!walked[x + 1][y] && isValidMove(matrix[x][y], matrix[x + 1][y])) {
            path(x + 1, y, shortestPathLen, currPathLen, matrix, walked);
        }
    }
    if (y - 1 > -1) {
        if (!walked[x][y - 1] && isValidMove(matrix[x][y], matrix[x][y - 1])) {
            path(x, y - 1, shortestPathLen, currPathLen, matrix, walked);
        }
    }
    if (y + 1 < columns) {
        if (!walked[x][y + 1] && isValidMove(matrix[x][y], matrix[x][y + 1])) {
            path(x, y + 1, shortestPathLen, currPathLen, matrix, walked);
        }
    }


    walked[x][y] = 0;

}

int main() {
    char matrix[rows][columns] = {
        {'S', 'a', 'b', 'q', 'p', 'o', 'n', 'm'},
        {'a', 'b', 'c', 'r', 'y', 'x', 'x', 'l'},
        {'a', 'c', 'c', 's', 'z', 'E', 'x', 'k'},
        {'a', 'c', 'c', 't', 'u', 'v', 'w', 'j'},
        {'a', 'b', 'd', 'e', 'f', 'g', 'h', 'i'}
    };

    int shortestPathLen = rows * columns + 1;
    int currShortestPath = rows * columns + 1;
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < columns;j++) {
            if (matrix[i][j] == 'a') {
                bool walked[rows][columns] = { 0 };
                int currPathLen = 0;
                path(i, j, currShortestPath, currPathLen, matrix, walked);
                // da se dobavi izvejdane na nai kratkiq put
                if (shortestPathLen > currShortestPath) {
                    shortestPathLen = currShortestPath;
                }
            }
        }
    }
    if (shortestPathLen == rows * columns + 1) {
        cout << "no path" << endl;
        return -1;
    }
    else {
        cout << shortestPathLen << endl;
    }


}