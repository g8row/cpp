#include <iostream>
using namespace std;

int main(){
    
}



//zad1
/*     int a;
    cin >> a;
    switch(a){
        case 1: cout << "Monday\n"; break;
        case 2: cout << "Tuesday\n"; break;
        case 3: cout << "Wednesday\n"; break;
        case 4: cout << "Thursday\n"; break;
        case 5: cout << "Friday\n"; break;
        case 6: cout << "Saturday\n"; break;
        case 7: cout << "Sunday\n"; break;
        default: cout << "Invalid day\n"; break;
    } */
    
//zad2
/* float a,b,c;
    cin >> a >> b >> c;
    float big = 0.0;
    if (a>0 || b>0 || c>0){
        if(a > b && a > c){
            big = a;
            a=0;
        }else if(b>c){
            big = b;
            b=0;
        }else{
            big = c;
            c=0;
    }

    if(a+b+c>big){
        cout << "This triangle exists.\n";        
    }else{
        cout << "This triangle does not exist.\n";
    }
    }else{
        cout << "invalid";
    }
     */

//zad3
/* float a, b, c;
        cin >> a >> b >> c;
        if(c < a || c > b){
            cout << "The number is outside of the interval.\n";
        }else if (c > a || c < b){
            cout << "The number is within the given interval. The interval is open.\n";
        }else{
            cout << "The number is within the given interval. The interval is closed.\n";
        } */

//zad4
    //ако е && компилатора вижда, че първото условие е 0, следователно не
    //проверява второто, в което има грешка(деление на 0). Когато е ||, стига до него и дава грешка

//zad5
    //c-=5 превръща c в 0
    //c+=0 == 0+=0
    //if(0) false
    //cout << 0

//zad6
/*     int a;
    cin >> a;

    if(a<0 || a>12){
    if(a%2==0){
        switch (a)
        {
        case 0: cout << "0 ";
        case 2: cout << "2 ";
        case 4: cout << "4 ";
        case 6: cout << "6 ";
        case 8: cout << "8 ";
        case 10: cout << "10 ";
        case 12: cout << "12 "; break;
        default: break;
        }
    }else{
        switch (a)
        {
        case 1: cout << "1 ";
        case 3: cout << "3 ";
        case 5: cout << "5 ";
        case 7: cout << "7 ";
        case 9: cout << "9 ";
        case 11: cout << "11 "; break;
        default: break;
        }
    }
    } */

//zad 7
/* int a, b, c;
    cin >> a >> b >> c;

    if(b != 0 && c != 0 && a/b!=0){
        cout << (a/=b) + (b/=c) + (c/=a);
    }else{
        cout << "invalid\n";
    } */

//zad 8
    /* int a, b, c;
    cin >> a >> b >> c;
    int fir, sec, thi;
    
    bool a_greater_b = a>b, b_greater_c=b>c, c_greater_a=c>a;

    if(a_greater_b && !c_greater_a){
        thi = a;
        if(b_greater_c){
            sec = b;
            fir = c;
        }else{
            sec = c;
            fir = b;
        }
    }else{
        if(b_greater_c){
            thi = b;
            if(c_greater_a){
                sec = c;
                fir = a;
            }else{
                sec = a;
                fir = c;
            }
        }else{
            thi = c;
            if(a_greater_b){
                sec = a;
                fir = b;
            }else{
                sec = b;
                fir = a;
            }
        }
    }

    cout << fir << sec << thi << endl; */

//zad9
    /* int r, x, y;
    cin >> r >> x >> y;
    if(x*x + y*y == r*r){
        cout << "On the circle";
    }else if (x*x + y*y >= r*r){
        cout << "Out of the circle";
    }else{
        cout << "In the circle";
    } */
