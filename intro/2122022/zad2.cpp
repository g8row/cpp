#include <iostream>
using namespace std;

void init(bool bl[], size_t size){
    for(size_t i=0; i<size; i++){
        bl[i] = 0;
    }
}

bool isDiverse(const char* arr){
    bool bl[26];
    init(bl, 26);
    while(*arr!='\0'){
        if(*(bl+((*arr)-'a'))){
            return false;
        }
        *(bl+((*arr)-'a'))=true;
        arr++;
    }
    return true;
}

int main (){
    char arr[] = "abcde";

    cout << isDiverse(arr) << endl;
}