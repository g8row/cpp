#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char* str, int len){
    bool result = 1;
    char* end = str + len - 1;
    while(result){
        if(*str != *end){
            result = 0;
        }
    }
    return result;
}
void biggestPalindrome(char* str, char*& res, int& len){
    int leng = strlen(str);
    int biggestLength = 1;
    res = str;
    len=1; 

    for(int i=0;i<leng-1;i++){
        for(int j=i+1;j<leng;j++){
            if(isPalindrome(str+i,j)){
                if(j-i>biggestLength){
                    biggestLength=j-i;
                    res=str+i;
                }
            }
        }
    }
    
}

int main(){
    char* str;
    
    char* res;
    int len;

    biggestPalindrome("alabbabobbobracrd", res, len);

    for(int i=0;i<len;i++){
        cout << *(res+i);
    }
}