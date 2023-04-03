#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void print(char matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void findWordRec(char matrix[MAX_SIZE][MAX_SIZE], int rows, int columns, char* word, bool& isFound, bool** visited, int currX, int currY) {

    if (currX < 0 || currX >= rows || currY < 0 || currY >= columns) {
        return;
    }

    if (visited[currX][currY]) {
        return;
    }

    if (*word == '\0') {
        cout << "not valid" << endl;
        return;
    }

    if (matrix[currX][currY] != *word) {
        return;
    }

    if (*(word + 1) == '\0') {
        isFound = true;
        matrix[currX][currY] = '#';
        return;
    }

    visited[currX][currY] = 1;

    findWordRec(matrix, rows, columns, word + 1, isFound, visited, currX + 1, currY);
    findWordRec(matrix, rows, columns, word + 1, isFound, visited, currX, currY + 1);
    findWordRec(matrix, rows, columns, word + 1, isFound, visited, currX - 1, currY);
    findWordRec(matrix, rows, columns, word + 1, isFound, visited, currX, currY - 1);

    if (isFound) {
        matrix[currX][currY] = '#';
        return;
    }

    visited[currX][currY] = 0;
}

bool findWord(char matrix[MAX_SIZE][MAX_SIZE], int rows, int columns, char* word) {
    bool isFound = false;
    bool** visited = new bool* [rows];
    for (int i = 0;i < rows;i++) {
        visited[i] = new bool[columns] {0};
    }
    for (int i = 0;i < rows && !isFound;i++) {
        for (int j = 0;j < columns && !isFound;j++) {
            if (matrix[i][j] != '#') {
                findWordRec(matrix, rows, columns, word, isFound, visited, i, j);
            }
        }
    }

    for (int i = 0;i < rows;i++) {
        delete[] visited[i];
    }
    delete[] visited;
    return isFound;
}

void interactive() {
    int n, m;
    cin >> n >> m;
    if (n > MAX_SIZE || m > MAX_SIZE || n < 1 || m < 1) {
        cout << "invalid input" << endl;
        throw;
    }

    char matrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> matrix[i][j];
        }
    }

    char word[100];
    cin >> word;

    cout << findWord(matrix, n, m, word);
}

int main() {
    char matrix[MAX_SIZE][MAX_SIZE] = {
        {'#','m','e','m','o'},
        {'#','f','o','o','t'},
        {'d','a','d','d','h'},
        {'t','o','p','r','e'}
    };
    char word[] = "mother";
    cout << findWord(matrix, 4, 5, word) << endl;
    print(matrix, 4, 5);
}