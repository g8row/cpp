#include <iostream>
#include <cstring>

using namespace std;

void splitWords(const char* arr, char words[][60], int& wordcount){
    int wordpos = 0;
    while(*arr!='\0'){    
        if(*arr!=' '){
            if(*arr!=','){
                *((*words)+wordpos) = *arr;
            }
            wordpos++;
        }else{
            if(wordpos!=0){
            words++;
            wordcount++;
            wordpos=0;
            }
        }
        arr++;
    }
    wordcount++;
}
void printWords(char words[][60], int wordcount){
    for(int i=0; i<wordcount;i++){
        cout << *words;
        cout << endl;
        words++;
    }
}
int main(){
    char arr[] = "   ab abc   ";
    char words[1024][60];
    int wordcount = 0;
    splitWords(arr, words, wordcount);
    printWords(words, wordcount);
}   