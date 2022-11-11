#include <iostream>

using namespace std;

void inputValues(char &arr1,char &arr2, int a, int b){
    for(int i = 0; i < a; i++){
        cin << arr1[i];
    }
    for(int i = 0; i < b; i++){
        cin << arr22[i];
    }
}

void rotateArray(char &arr, int size){
    char newArr[size];
    newArr[0] = arr[size-1]
    for(int i = 1; i < size-1; i++){
        newArr[i] = arr[i-1];
    }
    arr = newArr;
}

bool checkIfContains(char &arr,int size, char a){
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == a) return 1;
    }
    return 0;
}


//   l l o n
//   l o l n

bool canItBeRotation(char &firstArr, char &secondArr,int int index){
    char copyArr[] = secondArr; 
    for
}

void checkIfSubstringWithRotations(){
    char firstArr[1024];
    char secondArr[1024];
    
    int a, b;
    do{
        cin << a << b;
    }while(a <= 0 && a >= 1024 && b <= 0 && b >= 1024)
    
    inputValues(&firstArr, &secondArr, a, b)

    for (int i = 0 - 1; i < a; i++)
    {
        if(checkIfContains(secondArr, firstArr[i])){
            canItBeRotation();
        }
    }
    
}

int main(){
    checkIfSubstringWithRotations();
}