#include <iostream>

using namespace std;

bool isNeighbour(int num){
    int lastDigit = num % 10;
    num /= 10;
    while(num > 0){
        if(num % 10 == lastDigit){
            return false;
        }
        lastDigit = num % 10;
        num /= 10;
    }
    return true;
}

int diffInInterval(int min, int max){
    int biggest = -1;
    int smallest = 0;

    for (int i = min; i <= max; i++)
    {
        if(isNeighbour(i))
        {
            smallest = i;
            break;
        } 
    }

    for (int i = max; i >= min; i--)
    {
        if(isNeighbour(i))
        {
            biggest = i;
            break;
        } 
    }
    
    return biggest - smallest;
}

bool validateInput(int n, int k){
    return n>0 && k>0;
}

int main (){
    int n, k;

    do{
        cin >> n >> k;
    }while(!validateInput(n,k));

    int diff = diffInInterval(n, k);

    if(diff>0){
        cout << diff << endl;
    }else{
        cout << "No adjacent numbers!" << endl;
    }
}