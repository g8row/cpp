#include <iostream>
//#include <cmath>
using namespace std;

double sqrt(double num) {

    double x1 = num / 2;
    double epsilon = 1e-12;

    while (x1 - (num / x1) > epsilon) {

        x1 = (x1 + (num / x1)) / 2;

    }

    return x1;

}

int validSize(){
    int result;
    cin >> result;

    while(result<=0){
        cout << "Invalid input" << endl;
        cin >> result;
    }
    return result;
}

double distBetween2Points(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void enterCoordinates(int size, double& distance){
    int prevX, prevY;
    cin >> prevX >> prevY;
    for(int i = 0; i < size-1; i++){
        int x, y;
        cin >> x >> y;
        distance+=distBetween2Points(prevX,prevY,x,y);
        prevX = x;
        prevY = y;
    }
}

double abso(double n){
    return (n>0) ? n : -n;
}

bool isDistEqual(double distance1, double distance2){
    return (abso(distance1-distance2)<0.01);
}

int main(){

    int size1, size2;
    double distance1 = 0, distance2 = 0;
    size1 = validSize();

    enterCoordinates(size1, distance1);
    
    size2 = validSize();

    enterCoordinates(size2, distance2);

    (isDistEqual(distance1, distance2)) ?  cout << "true\n" << distance1 << endl : cout << "false" << endl;
    

}