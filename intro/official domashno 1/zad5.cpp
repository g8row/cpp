#include <iostream>
//#include <Windows.h>
#include <unistd.h>

using namespace std;

void coutSpaces(int n){
    for(int i = 0; i < n; i++){
        cout << " ";
    }
}

int main (){
    for(int i = 0; i < 30; i++){
        coutSpaces(i); cout << "__________________________" << endl; 
        coutSpaces(i); cout << "|  |     |     |     | |  \\" << endl;
        coutSpaces(i); cout << "|__|_____|_____|_____|_|___\\" << endl;
        coutSpaces(i); cout << "|                    | |    \\" << endl;
        coutSpaces(i); cout << "`--(o)(o)--------------(o)--'" << endl;
        sleep(1);
        system("clear");
    }
}