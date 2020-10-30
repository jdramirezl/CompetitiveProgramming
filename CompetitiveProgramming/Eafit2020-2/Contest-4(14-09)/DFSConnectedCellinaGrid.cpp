#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(x, n) for (int i = x; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define allgreater(v) v.begin(), v.end(), greater<int>()
#define formap(map) for (const auto &[key, value] : map)
#define ms(ar, val) memset(ar, val, sizeof ar)
#define vvi vector<vector<int>>
typedef long long ll;
typedef long double ld;

using namespace std;


int xCambio[] = {1, 1, 1, 0, -1, -1, -1, 0};
int yCambio[] = {1, 0, -1, -1, -1, 0, 1, 1};

int func(vvi &matrix, vvi &visited, int x, int y, int n, int m){
    visited[x][y] = 1;
    int child = 1;

    for(int i = 0; i<8; ++i){
        int nextX = x+xCambio[i];
        int nextY = y+yCambio[i];

        if(nextX>=n || nextX<0 || nextY>=m || nextY<0) continue;
        if(matrix[nextX][nextY] == 0) continue;
        if(visited[nextX][nextY] == 1) continue;
        child += func(matrix,  visited, nextX, nextY, n, m);
    }

    return child;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vvi isles(n, vector<int>(m));
    vvi visited(n, vector<int> (m));

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin >> isles[i][j];
            visited[i][j] = 0;
        }
    }

    int total = 0;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(!visited[i][j] && isles[i][j] == 1){
                total = max(total, func(isles, visited, i, j, n, m));
            }
        }
    }

    cout << total << endl;
}