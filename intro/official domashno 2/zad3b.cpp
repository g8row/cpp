#include <iostream>
using namespace std;

int tallestBuilding(int* buildings, int n) {
    int result = 0;
    for (int i = 0;i < n;i++) {
        if (result < *buildings) {
            result = *buildings;
        }
        buildings++;
    }
    return result;
}


int main() {
    int n;
    cin >> n;
    int* buildings = new int[n];

    for (int i = 0;i < n;i++) {
        cin >> buildings[i];
    }

    int litFloors = 0;
    int coveredFloors = buildings[0];

    int tallest = tallestBuilding(buildings, n) + 1;

    char** scheme = new char* [n];

    for (int i = 0; i < n; i++)
    {
        scheme[i] = new char[tallest];
    }


    for (int i = 0;i < n;i++) {
        int pos = 0;
        if (coveredFloors <= buildings[i]) {
            litFloors = buildings[i] - coveredFloors;
            coveredFloors = buildings[i];
        }
        else {
            litFloors = 0;
            coveredFloors--;
        }
        for (int j = 0;j < buildings[i] - litFloors;j++) {
            scheme[i][pos] = '#';
            pos++;
        }
        for (int j = 0;j < coveredFloors - buildings[i];j++) {
            scheme[i][pos] = '-';
            pos++;
        }
        for (int j = 0;j < litFloors;j++) {
            scheme[i][pos] = '*';
            pos++;
        }
        while (pos < tallest) {
            scheme[i][pos] = '\\';
            pos++;
        }
    }

    for (int i = tallest - 1;i >= 0;i--) {
        for (int j = 0;j < n;j++) {
            cout << scheme[j][i];
        }
        cout << endl;
    }

    for (int i = 0; i < tallest; i++)
    {
        delete[] scheme[i];
    }

    delete[] scheme;

    delete[] buildings;
}