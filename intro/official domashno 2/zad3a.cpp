#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    size_t* buildings = new size_t[n];

    for (int i = 0;i < n;i++) {
        cin >> buildings[i];
    }

    size_t litFloors = 0;
    size_t coveredFloors = buildings[0];

    for (int i = 1;i < n;i++) {
        if (coveredFloors <= buildings[i]) {
            litFloors += buildings[i] - coveredFloors;
            coveredFloors = buildings[i];
        }
        else {
            coveredFloors--;
        }
    }

    cout << litFloors << endl;



    delete[] buildings;
}