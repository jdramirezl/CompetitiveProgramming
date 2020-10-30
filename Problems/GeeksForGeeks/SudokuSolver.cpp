//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int board[9][9];
int visited[9][9];

void print(){
    for(auto & i : board){
        for(auto & j : i){
            cout << setw(5) << j << setw(5);
        }
        cout << "\n\n";
    }
}

bool isSafe(int row, int col, int num){
    int i, j;

    /* Row && column */
    for (i = 0; i < 9; i++){
        if (board[i][col] == num) return false;
        if (board[row][i] == num) return false;
    }

    /* quadrant */
    int srow, scolumn;

    //Check row start
    if(row >= 6) srow = 6;
    else if(row >= 3) srow = 3;
    else srow = 0;

    //Check column start
    if(col >= 6) scolumn = 6;
    else if(col >= 3) scolumn = 3;
    else scolumn = 0;

    for (i = srow; i<=(srow+2); ++i){
        for (j = scolumn; j<=(scolumn+2); ++j){
            if(board[i][j] == num) return false;
        }
    }

    return true;
}

bool solved(int col, int row) {

    //Array de ya puestos e ignorar
    if (row >= 9) {
        if (col >= 8) return true;
        else return solved(col + 1, 0);
    }

    /* Check if the number on the board is not a default number */
    if (visited[row][col] == 1) return solved(col, row + 1);
    else {
        for (int j = 1; j < 10; ++j) {
            if (isSafe(row, col, j)) {
                board[row][col] = j;

                if (solved(col, row + 1)) return true;

                board[row][col] = -1; // BACKTRACK
            }
        }
    }

    //No posible numbers
    return false;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i<9; ++i){
            for(int j = 0; j<9; ++j){
                cin >> board[i][j];
                if(board[i][j] == 0){
                    board[i][j] = -1;
                    visited[i][j] = 0;
                }
                else visited[i][j] = 1;
            }
        }

        solved(0,0);

        print();

        /*
        for(auto & i : board){
            for(auto & j : i){
                cout << j << " ";
            }
        }
        */
    }
}
