#include <iostream>
#include <cstring>

using namespace std;

char big2Small(char ch){
    if(ch<'A' || ch>'Z'){
        return ch;
    }
    return ch-'A'+'a';
}

char small2Big(char ch){
    if(ch<'a' || ch>'z'){
        return ch;
    }
    return ch+'A'-'a';
}

void invert(
)

int main(){
    char arr[] = "I aM a BiG bAbY";
    char invert[];
    strcpy(invert, arr);
    invert(arr);
}