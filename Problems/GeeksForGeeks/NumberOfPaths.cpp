#include <bits/stdc++.h>
using namespace std;


long long  aux(int row, int col, int m, int n){
    if(row >= m || col >= n) return 0;
    if(row == m -1 && col == n-1) return 1;

    return aux(row+1, col, m, n) + aux(row, col+1, m, n);
}

long long  numberOfPaths(int m, int n){
    return aux(0, 0, m, n);
}

/*
------
    |1 2 3 |
    |4 5 6 |
    |7 8 9 |
------
3x3 = 6
*/