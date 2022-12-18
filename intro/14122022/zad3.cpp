#include <iostream>
using namespace std;

int getSumOfCol(const int matrix[3][3], int col){
    int res = 0;
    for(int i=0; i<3; i++){
        res+=matrix[i][col];
    }
    return res;
}

int biggestSumOfCol(const int matrix[3][3]){
    int biggestSum = getSumOfCol(matrix, 0);
    int whichColumn=0;
    for(int i=1;i<3;i++){
        int sum = getSumOfCol(matrix, i);
        if(sum>biggestSum){
            biggestSum=sum;
            whichColumn=i;
        }
    }
    return whichColumn;
}
void printCol(int matrix[3][3], int col){
    for(int i=0; i<3; i++){
        cout << matrix[i][col];
    }
}
int main(){
    int matrix [3][3] ={
        1,2,3,
        4,5,6,
        3,2,1
    };
    printCol(matrix, biggestSumOfCol(matrix));

}