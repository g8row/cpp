#include <iostream>
using namespace std;

int lengthWOSymbol(const char* str, char symbol){
    int length = 0;
    while(*str){
        if(*str!=symbol){
            length++;
        }
        str++;
    }
    return length;
}

char* removeChar(const char* str, char symbol){
    char* result = new char[lengthWOSymbol(str,symbol)+1];
    char* beg = result;
    while(*str){
        
        if(*str!=symbol){
            *result=*str;
            result++;
        }
        str++;
    }
    return beg;
}

int main(){
    char* result = removeChar("Hello world!", 'o');
    cout << result << endl;
    delete [] result;
}