#include <iostream>
using namespace std;

const int matrixSize = 10;

void fillMatrix(int matrix[matrixSize][matrixSize]){
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixSize;j++){
            matrix[j][i]=i*matrixSize+j+1;
        }
    }
}

int main(){
    int matrix[matrixSize][matrixSize];
    fillMatrix(matrix);

    for(int i=0;i<matrixSize;i++){
        int res = 0;
        cout << res;
        for(int j=0;j<=i;j++){
            cout << "+" << matrix[i-j][j];
            res += matrix[i-j][j];
        }
        cout << "=" << res << endl;
    }
    for(int i=1;i<matrixSize;i++){
        int res = 0;
        cout << res;
        for(int j=0;j<=matrixSize-1-i;j++){
            cout << "+" << matrix[i+j][matrixSize-1-j];
            res += matrix[i+j][matrixSize-1-j];
        }
        cout << "=" << res << endl;
    }

}