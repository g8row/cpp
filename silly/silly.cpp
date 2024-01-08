#include <iostream>
//#include <Windows.h>
#include <unistd.h>

using namespace std;

void coutSpaces(int n) {
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}

int main() {
    for (int i = 0; i < 50; i++) {
        char row1[100] = { 32, 95, 95, 95, 95, 95, 32, 32, 32, 95, 95, 95, 95, 95 };
        char row2[100] = { 47, 32, 32, 32, 32, 32, 92, 32, 47, 32, 32, 32, 32, 32,  92 };
        char row3[100] = { 124, 32, 32, 84, 72, 69, 32, 87, 79, 82, 76, 68, 32, 32, 124 };
        char row4[100] = { 32 ,92 ,32 ,73 ,83 ,32 ,84 ,69 ,68 ,73 ,39 ,83 ,32 ,47 };
        char row5[100] = { 32, 32, 92, 32, 32, 32, 32, 32, 32, 32, 32, 32, 47 };
        char row6[100] = { 32, 32,32, 92, 32, 32, 32, 32, 32, 32, 32, 47 };
        char row7[100] = { 32, 32, 32,32,92, 32, 32, 32, 32, 32, 47 };
        char row8[100] = { 32, 32,32,32,32, 92, 32, 32, 32, 47 };
        char row9[100] = { 32, 32,32, 32,32,32,92, 32, 47 };

        coutSpaces(i); cout << row1 << endl;
        coutSpaces(i); cout << row2 << endl;
        coutSpaces(i); cout << row3 << endl;
        coutSpaces(i); cout << row4 << endl;
        coutSpaces(i); cout << row5 << endl;
        coutSpaces(i); cout << row6 << endl;
        coutSpaces(i); cout << row7 << endl;
        coutSpaces(i); cout << row8 << endl;
        coutSpaces(i); cout << row9 << endl;

        //Sleep(70);
        //system("CLS");
        sleep(1);
        system("clear");
    }
}