#include <iostream>
#include <cmath>

using namespace std;

//8 queens problem solution

int solution_count = 1;
int board[20];

void queen(int row, int size);
int place(int row, int col);
void print_solution(int size);

int main() {
    int size = 0;
    cout << "Enter number of queens: ";
    cin >> size;
    queen(1, size);
    return 0;
}

void print_solution(int size) {
    if(size == 2 || size == 3) {
        cout << "There is no solution!" << endl;
    }
    cout << endl << "Solution: " << solution_count++ << endl << endl;
    for(int i = 1; i <= size; i++) {
        cout << "\t " << i;
    }
    for(int i = 1; i <= size; i++) {
        cout << "\n\n" << i;
        for(int j = 1; j <= size; j++) {
            if(board[i] == j) {
                cout << "\t Q";
            }
            else {
                cout << "\t -";
            }
        }
        cout << endl;
    }
}

int place(int row, int col) {
    for(int i = 1; i <= row - 1; i++) {
        if(board[i] == col) {
            return 0;
        }
        else if(abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

void queen(int row, int size) {
    for(int col = 1; col <= size; col++) {
        if(place(row, col) == 1) {
            board[row] = col;
            if(row == size) {
                print_solution(size);
            }
            else {
                queen(row + 1, size);
            }
        }
    }
}