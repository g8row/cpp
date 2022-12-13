#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;


bool LOST=0;
const int MAX_SIZE = 10;

int SIZE;
int NUMBER_OF_MINES;

int state[MAX_SIZE][MAX_SIZE]; //-2 = is Marked; -1 = isnt Uncovered; 0 = Uncovered;
int isMine[MAX_SIZE][MAX_SIZE];//-1 is Mine, >=0 = number of mines nearby

int MARKED = 0;
int OPENED = 0;

void openEmptySquares(int x, int y){
    for(int i = -1; i < 2;i++){
            for(int j = -1; j < 2;j++){
                if(x+j<SIZE && x+j>=0 && y+i<SIZE && y+i>=0){
                    if(state[x+j][y+i]==-1){
                        state[x+j][y+i]=0;
                        OPENED++;
                        if(isMine[x+j][y+i]==0){
                            openEmptySquares(x+j,y+i);
                        }
                        
                    }
                }
            }
        }
}

void mark(int x, int y){
    if(state[x][y]==-1){
        state[x][y]=-2;
        MARKED++;
    }else{
        cout << "Square cannot be marked!\n";
    }
}

void unmark(int x, int y){
    if(state[x][y]==-2){
        state[x][y]=-1;
        MARKED--;
    }else{
        cout << "Square cannot be unmarked!\n";
    }
}

void open(int x, int y){
    if(state[x][y] == -1){
        if(isMine[x][y] == -1){
            LOST = 1;
            cout << "You Lost!\n";
            return;
        }
        state[x][y] = 0;
        if(isMine[x][y]==0){
            openEmptySquares(x,y);
        }
        OPENED++;
    }else{
        cout << "Square cannot be opened!\n";
    }
}

int numberOfSquare(int x, int y){
    int number=0;
    for(int i = -1; i < 2;i++){
        for(int j = -1; j < 2;j++){
            if(x+j<SIZE && x+j>=0 && y+i<SIZE && y+i>=0)
                    if(isMine[x+j][y+i]==-1)
                        number++;
        }
    }
    return number;
}

void fillMines() {
    for (int i = 0;i < SIZE;i++) {
        for (int j = 0;j < SIZE;j++) {
            isMine[i][j] = 0;
        }
    }
    for (int i = 0;i < NUMBER_OF_MINES;i++) {
        srand((size_t)time(NULL));
        int randomx = rand() % (SIZE);
        int randomy = rand() % (SIZE);
        while (isMine[randomx][randomy] == -1) {
            randomx = rand() % (SIZE);
            randomy = rand() % (SIZE);
        }
        isMine[randomx][randomy] = -1;
    }
    for (int i = 0;i < SIZE;i++) {
        for (int j = 0;j < SIZE;j++) {
            if(isMine[j][i]!=-1){
                isMine[j][i] = numberOfSquare(j,i);
            }
        }
    }
    
}

void fillState() {
    for (int i = 0;i < SIZE;i++) {
        for (int j = 0;j < SIZE;j++) {
            state[j][i] = -1;
        }
    }
}

void validSizeAndMines() {
    int temp;
    cout << "Please enter size: ";
    cin >> temp;

    while (temp<3 && temp>10) {
        cout << "Invalid input. Please enter size again.\n";
        cin >> temp;
    }
    SIZE = temp;

    cout << "Please enter number of mines: ";
    cin >> temp;

    while (temp<1 && temp>(3 * SIZE)) {
        cout << "Invalid input. Please enter number of mines again.\n";
        cin >> temp;
    }
    NUMBER_OF_MINES = temp;
}

void printArray(int arr[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0;i < SIZE;i++) {
        for (int j = 0;j < SIZE;j++) {
            char icon;

            switch (arr[j][i])
            {
            case -2: icon = '^'; break;
            case -1: icon = '#'; break;
            default: icon = isMine[j][i]+'0';break;
            }
            cout << "[" << ((icon=='0') ? ' ' : icon) << "]";
        }
        cout << endl;
    }
}


int main() {
    validSizeAndMines();

    fillMines();
    fillState();

    while(LOST == 0 && MARKED+OPENED!=SIZE*SIZE){
        printArray(state);

        cout << "\nPlease enter a command.\n";
        char command[100];
        int x, y;
        cin >> command >> x >> y;
        cout << endl;
        if(x>=SIZE || x<0 || y>=SIZE || y<0){
            cout << "Invalid command! Try again.\n";
            continue;
        }
        if(!strcmp(command, "mark")){
            mark(x,y);
        }else if (!strcmp(command, "unmark")){
            unmark(x,y);
        }else if (!strcmp(command, "open")){
            open(x,y);
        }else{
            cout << "Invalid command! Try again.\n";
        }
        cout << endl;
    }

    if(!LOST){
        cout << "You win!\n";
    }
}