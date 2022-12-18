#include <iostream>
using namespace std;

bool isLower(char symb){
    return symb>='a' && symb<='z';
}

bool isCapital(char symb){
    return symb>='A' && symb<='Z';
}

void countLetters(const char* str, int hist[26]){
    while(*str){
        if(isLower(*str)){
            hist[*str-'a']++;
        }else if(isCapital(*str)){
            hist[*str-'A']++;
        }
        str++;
    }
}

char* constructHistogram(int hist[26]){
    int length = 0;
    for(int i=0;i<26;i++){
        length+=hist[i];
    }
    char* result = new char[length];
    char* beg = result;
    for(int i=0;i<26;i++){
        for(int j=0;j<hist[i];j++){
            *result = i+'a';
            result++;
        }
    }
    return beg;
}

int main(){
    int hist[26] = {0};
    countLetters("Hello World!", hist);
    char* result = constructHistogram(hist);
    cout << result << endl;
    delete [] result;
}