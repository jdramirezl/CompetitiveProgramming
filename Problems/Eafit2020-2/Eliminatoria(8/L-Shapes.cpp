#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;

int N;
int letters[26];

void print(vector<vector<char>>& grid){
    cout << "\nSTART" << endl;
    for(const auto &row: grid){
        for(const auto &col: row){
            cout << col << " ";
        }
        cout << endl;
    }
    cout << "END\n" << endl;
}

bool backtracking(vector<vector<char>>& grid, int row, int col, int pos)
{
    if (row == N - 1 && col >= N) //>= para 2 saltos
        return true;

    if (col >= N) { // >= por si se hacen 2 saltos que no hayan errores
        row++;
        col = 0;
    }

    if (pos >= 26){
        pos = 0;
    }


    if (grid[row][col] != ' ')
        return backtracking(grid, row, col + 1, pos);



    for (int num = 1; num <= 4; num++){
        if (num == 1){
            if(
                    col + 1 < N && col + 1 > -1 && grid[row][col+1] == ' ' &&
                    row - 1 > -1 && row - 1 < N && grid[row-1][col+1] == ' '
                    ){
                grid[row][col] = letters[pos];
                grid[row][col+1] = letters[pos];
                grid[row-1][col+1] = letters[pos];
                if(backtracking(grid, row, col + 2, pos + 1)){

                    return true;
                }
                grid[row][col] = ' ';
                grid[row][col+1] = ' ';
                grid[row-1][col+1] = ' ';
            }
        }
        else if(num == 2){
            if(
                    row + 1 < N && row + 1 > -1 && grid[row+1][col] == ' ' &&
                    col + 1 > -1 && col + 1 < N && grid[row+1][col+1] == ' '
                    ){
                grid[row][col] = letters[pos];
                grid[row+1][col] = letters[pos];
                grid[row+1][col+1] = letters[pos];
                if(backtracking(grid, row, col + 1, pos + 1)){

                    return true;
                }
                grid[row][col] = ' ';
                grid[row+1][col] = ' ';
                grid[row+1][col+1] = ' ';
            }
        }
        else if(num == 3){
            if(
                    row + 1 < N && row + 1 > -1 && grid[row+1][col] == ' ' &&
                    col + 1 > -1 && col + 1 < N && grid[row][col+1] == ' '
                    ){
                grid[row][col] = letters[pos];
                grid[row+1][col] = letters[pos];
                grid[row][col+1] = letters[pos];
                if(backtracking(grid, row, col + 2, pos + 1)){ 
                    return true;
                }
                grid[row][col] = ' ';
                grid[row+1][col] = ' ';
                grid[row][col+1] = ' ';
            }
        }
        else if(num == 4){
            if(
                    row + 1 < N && row + 1 > -1 && col + 1 > -1 && col + 1 < N &&
                    grid[row+1][col+1] == ' ' && grid[row][col+1] == ' '
                    ){
                grid[row][col] = letters[pos];
                grid[row+1][col+1] = letters[pos];
                grid[row][col+1] = letters[pos];
                if(backtracking(grid, row, col + 2, pos + 1)){
                    return true;
                }
                grid[row][col] = ' ';
                grid[row+1][col+1] = ' ';
                grid[row][col+1] = ' ';
            }
        }
    }
    return false;
}
int main() {
    int R, C;
    cin >> N >> R >> C;
    R--; C--;

    for(int i = 'A'; i<='Z'; i++) letters[i - 'A'] = i;

    vector<vector<char>> matriz(N, vector<char>(N, ' '));
    matriz[R][C] = '.';
    backtracking(matriz, 0, 0, 0);
    print(matriz);
    return 0;
}