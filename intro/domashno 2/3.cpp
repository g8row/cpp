#include <iostream>
#include <cmath>

using namespace std;

double distOf2Points(int x, int y){
    return sqrt(x*x + y*y);
}

double sumOfTriangleSides(int ax, int ay, int bx, int by, int cx, int cy){
    return distOf2Points(ax, ay) + distOf2Points(bx, by) + distOf2Points(cx, cy);
}

int main() {
    cout << sumOfTriangleSides(1, 1, 4, 7, 0, 10);
}