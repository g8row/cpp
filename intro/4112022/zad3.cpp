#include <iostream>

using namespace std;

bool isLeapYear(unsigned year){
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

unsigned int daysInMonth(unsigned month, unsigned year){
    switch (month)
    {
    case 2: return (isLeapYear(year)) ? 29 : 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: return 31;
    default: return 30;
    }
}

void calculateDate(unsigned& days, unsigned& month, unsigned& year, unsigned daysPassed){
    if(month > 12 || days > daysInMonth(month, days)){
        cout << "invalid date" << endl;
        return;
    }
    
    days += daysPassed;
    while(days>daysInMonth(month, year)){
        days-=daysInMonth(month, year);
        if(month == 12){
            month = 1;
            year++;
        }else{
            month++;
        }
    }
}

int main(){
    unsigned days = 31, month = 11, year = 2022;

    calculateDate(days, month, year, 1000);

    cout << days << "." << month << "." << year << endl;
}