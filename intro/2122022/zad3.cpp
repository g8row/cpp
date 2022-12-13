#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(const char* arr){
    int len = strlen(arr);
    const char* end = arr+len-1;
    len/=2;
    while(len>0){
        if(*arr!=*end){
            return false;
        }
        arr++;
        end--;
        len--;
    }
    return true;
}

int main(){
    char arr[] = "abccaba";
    cout << isPalindrome(arr) << endl;
}