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

void pathfinder(int x, int y, int& shortestPathLen, int currPathLen, char matrix[rows][columns], bool walked[rows][columns], char* path) {

    currPathLen++;
    *path = matrix[x][y];
    path++;
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
            pathfinder(x - 1, y, shortestPathLen, currPathLen, matrix, walked, path);
        }
    }
    if (x + 1 < rows) {
        if (!walked[x + 1][y] && isValidMove(matrix[x][y], matrix[x + 1][y])) {
            pathfinder(x + 1, y, shortestPathLen, currPathLen, matrix, walked, path);
        }
    }
    if (y - 1 > -1) {
        if (!walked[x][y - 1] && isValidMove(matrix[x][y], matrix[x][y - 1])) {
            pathfinder(x, y - 1, shortestPathLen, currPathLen, matrix, walked, path);
        }
    }
    if (y + 1 < columns) {
        if (!walked[x][y + 1] && isValidMove(matrix[x][y], matrix[x][y + 1])) {
            pathfinder(x, y + 1, shortestPathLen, currPathLen, matrix, walked, path);
        }
    }
    *path = '\0';
    path--;
    walked[x][y] = 0;

}

int main() {
    char matrix[rows][columns] = {
        {'a', 'a', 'b', 'q', 'p', 'o', 'n', 'm'},
        {'a', 'b', 'c', 'r', 'y', 'x', 'x', 'l'},
        {'a', 'c', 'c', 's', 'z', 'E', 'x', 'k'},
        {'a', 'c', 'c', 't', 'u', 'v', 'w', 'j'},
        {'a', 'b', 'd', 'e', 'f', 'g', 'h', 'i'}
    };
    char path[1000] = { '\0' };
    int shortestPathLen = rows * columns + 1;
    int currShortestPath = rows * columns + 1;
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < columns;j++) {
            if (matrix[i][j] == 'a') {
                bool walked[rows][columns] = { 0 };
                int currPathLen = 0;
                pathfinder(i, j, currShortestPath, currPathLen, matrix, walked, path);
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
        cout << path << endl;
    }


}