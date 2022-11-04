#include <iostream>
using namespace std;

int main() {

    //zad1
    /*long long a;
    cin >> a;
    
    int result = 1;
    int resultCount = 0;
    for (int i = 0; i < 10; i++) {
        int count = 0;
        long long acopy = a;
        while (acopy > 0) {
            int n = acopy % 10;
            if (n == i) {
                count++;
            }
            acopy /= 10;
            cout << i << ": " << count << endl;
            cout << acopy << endl;
        }
        if (count > resultCount) {
            resultCount = count;
            result = i;
        }
    }
    cout << result;*/

    //zad2

    /*int a;
    cin >> a;
    int spaces = 0;
    for (int i = a; i > 0; i-=2) {
        
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
        spaces++;
    }

    spaces = a / 2 - 1;

    for (int i = 3; i < a+1; i += 2) {

        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
        spaces--;
    }*/

    //zad1
    /*long long n;
    cin >> n;
    long long result = 0;
    while(n > 10) {
        result = 0;
        long long ncopy = n;
        while (ncopy > 0) {
            result += ncopy % 10;
            ncopy /= 10;
            cout << result << endl;
            cout << ncopy << endl;
        }
        cout << result << endl;
        n = result;
    }
    cout << result;*/

    //zad2

    //int n;
    //cin >> n;

    //int prev1 = 0, prev2 = 1;

    //if (n == 0) {
    //    cout << 0;
    //}
    //if (n == 1) {
    //    cout << 1;
    //}

    //int result = 0;
    //for (int i = 1; i < n; i++) {
    //    result = prev1 + prev2;
    //    int buffer = prev2;
    //    prev2 = result;
    //    prev1 = buffer;
    //}
    //cout << result;

    //zad3
    /*int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }*/

    //zad4
    /*int n;
    cin >> n;
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    cout << result;*/

    //zad5
    /*for (int i = 111; i <= 999; i++) {
        int sum = 0;
        int icopy = i;
        for (int j = 0; j < 3; j++) {
            sum += icopy % 10;
            icopy /= 10;
        }
        if (sum < 10) {
            continue;
        }
        bool isSumPrime = true;
        for (int i = 2; i < sum ; i++) {
            if (sum % i == 0) {
                isSumPrime = false;
                break;
            }
        }
        if (isSumPrime) {
            cout << i << " ";
        }
    }*/
    //zad6

    /*int a;
    bool isSum10 = false;

    while (!isSum10) {
        cin >> a;
        int sum = 0;
        int acopy = a;
        while(acopy>0) {
            sum += acopy % 10;
            acopy /= 10;
        }
        if ((a + sum) % 10 == 0) {
            isSum10 = true;
        }
        else {
            cout << "Bad Number "  << (a + sum) << endl;
        }

    }*/

    //zad7
    int hours, minutes, hours2, minutes2;
    cin >> hours >> minutes >> hours2 >> minutes2;

    if (hours2 == hours) {
        if (minutes2 > minutes) {
            int buffer = hours;
            hours = hours2;
            hours2 = buffer;
            buffer = minutes;
            minutes = minutes2;
            minutes2 = buffer;
        }
    }
    else if (hours2 > hours) {
        int buffer = hours;
        hours = hours2;
        hours2 = buffer;
        buffer = minutes;
        minutes = minutes2;
        minutes2 = buffer;
    }

    while (hours2 <= hours) {
        int minutesCheck = 60;
        if (hours2 == hours) {  
            minutesCheck = minutes;
        }
        for (int i = minutes2; i < minutesCheck; i++) {
            cout << hours2 << ":" << ((i <= 10) ? '0' : '\0') << i;
            cout << endl;
        }
        hours2++;
        minutes2 = 0;
    }

}