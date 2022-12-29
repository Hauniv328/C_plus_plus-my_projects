#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

char board[3][3];
int t1 = 0, t2 = 0;
int turn = 1;

#define target_ind board[get_index1(target)][get_index2(target)]

void draw();
bool checking(int);
bool checking_end();
int get_index1(int);
int get_index2(int);

int main() {
    for (int i = 1; i <= 3; i++) {
        for (int i2 = 1; i2 <= 3; i2++) {
            t1++;
            board[i-1][i2-1] = (char)(t1 + 48);
        }
    } //setting board

    int input;
    while (true) { // main loop
        draw();

        if(checking_end()) {
            system("cls");
            if(turn == -1) {
                cout << "A win" << endl;
            }
            else {
                cout << "B win" << endl;
            }
            Sleep(1000);
            break;
        }
        if(t2 == 9) {
            system("cls");
            cout << "draw" << endl;
            Sleep(1000);
            break;
        }
        if (turn == 1) {
            cout << "input: ";
            input = getch() - 48;
            if (checking(input)) {
                cout << input << endl;
                cout << endl;
                board[get_index1(input)][get_index2(input)] = 'o';
            } else {
                cout << "Try again." << endl;
                Sleep(1000);
                system("cls");
                continue;
            }
        }

        else {
            cout << "input: ";
            input = getch() - 48;
            if (checking(input)) {
                cout << input << endl;
                cout << endl;
                board[get_index1(input)][get_index2(input)] = 'x';
            } else {
                cout << "Try again." << endl;
                Sleep(1000);
                system("cls");
                continue;
            }
        }

        system("cls");
        turn *= -1;
        t2++;
    }
}

void draw() { // drawing board
    t1 = 0;
    for (int i = 1; i <= 7; i++) {
        if(i % 2 == 1) {
            cout << "+-----+-----+-----+" << "\n";
        }
        else {
            t1++;
            for (int i2 = 1; i2 <= 3; i2++) {
                cout << "|  " << board[t1-1][i2-1] << "  ";
            }
            cout << "|\n";
        }
    }
}

bool checking(int target) { // check the input
    if(0 < target && target < 10 && (target_ind != 'o' && target_ind != 'x')) {
        return true;
    } else {
        return false;
    }
}

bool checking_end() { // check if this game end
    if(board[1][1] == board[1][0] && board[1][1] == board[1][2] || board[1][1] == board[0][1] && board[1][1] == board[2][1]) {
        return true;
    } else if(board[1][1] == board[0][0] && board[1][1] == board[2][2] || board[1][1] == board[0][2] && board[1][1] == board[2][0]) {
        return true;
    } else if (board[0][1] == board[0][0] && board[0][1] == board[0][2] || board[2][1] == board[2][0] && board[2][1] == board[2][2]) {
        return true;
    } else if(board[1][0] == board[0][0] && board[1][0] == board[2][0] || board[1][2] == board[0][2] && board[1][2] == board[2][2]) {
        return true;
    }
    
    else return false;
}

int get_index1(int target) {
    if(target % 3 == 0) {
        return target / 3 - 1;
    } else {
        return target / 3;
    }
}

int get_index2(int target) {
    if(target % 3 == 0) {
        return 2;
    } else {
        return target % 3 - 1;
    }
}
