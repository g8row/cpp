#include <iostream>
using namespace std;

const int N = 5;

void printMatrix(bool** visited) {
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cout << '[' << ((visited[i][j]) ? '*' : ' ') << ']';
        }
        cout << endl;
    }
    cout << endl;
}

void doesPathExistHelper(int startX, int startY, int endX, int endY, int maxVolume,
    int matrix[N][N], int currX, int currY, int currLoad, bool check1, bool& check2, bool** visited) {

    currLoad += matrix[currX][currY];
    if (currLoad > maxVolume || currLoad < 0) {
        return;
    }

    visited[currX][currY] = true;

    if (currX == endX && currY == endY) {
        printMatrix(visited);
        if (!check1) {
            check1 = true;
            visited[startX][startY] = 0;
            doesPathExistHelper(startX, startY, startX, startY, maxVolume, matrix, currX, currY, currLoad - matrix[currX][currY], check1, check2, visited);
        }
        else {
            check2 = true;
        }
        return;
    }

    if (!check2 && currX + 1 < N && !visited[currX + 1][currY]) {
        doesPathExistHelper(startX, startY, endX, endY, maxVolume, matrix, currX + 1, currY, currLoad, check1, check2, visited);
    }
    if (!check2 && currY - 1 > 0 && !visited[currX][currY - 1]) {
        doesPathExistHelper(startX, startY, endX, endY, maxVolume, matrix, currX, currY - 1, currLoad, check1, check2, visited);
    }
    if (!check2 && currX - 1 > 0 && !visited[currX - 1][currY]) {
        doesPathExistHelper(startX, startY, endX, endY, maxVolume, matrix, currX - 1, currY, currLoad, check1, check2, visited);
    }
    if (!check2 && currY + 1 < N && !visited[currX][currY + 1]) {
        doesPathExistHelper(startX, startY, endX, endY, maxVolume, matrix, currX, currY + 1, currLoad, check1, check2, visited);
    }
    if (check2) {
        cout << '(' << currX << ',' << currY << ')' << endl;
    }
    visited[currX][currY] = false;
}

bool doesPathExist(int startX, int startY, int endX, int endY, int maxVolume, int matrix[N][N]) {

    bool check2 = false;
    bool** visited = new bool* [N];
    for (int i = 0;i < N;i++) {
        visited[i] = new bool[N] {0};
    }
    doesPathExistHelper(startX, startY, endX, endY, maxVolume, matrix, startX, startY, 0, false, check2, visited);
    for (int i = 0;i < N;i++) {
        delete[] visited[i];
    }
    delete[] visited;
    return check2;
}




int main() {
    int maxVolume = 15;
    int matrix[N][N] = {
        {1 ,5 ,6 ,4 ,-2},
        {-4, 10, 4, -3, 20},
        {0 ,-4 ,2,-12, 5},
        {5 ,13 ,1 ,1 ,-7},
        {2 ,7 ,5 ,0 ,15}
    };
    int ofisX = 1, ofisY = 1;
    int houseX = 4, houseY = 3;
    cout << doesPathExist(ofisX, ofisY, houseX, houseY, maxVolume, matrix) << endl;
}
