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

vvi visited;
int xCambio[] = {1, 1, 1, 0, -1, -1, -1, 0};
int yCambio[] = {1, 0, -1, -1, -1, 0, 1, 1};

int func(vvi &matrix, vvi &visited, int x, int y){
    
    for(int i = 0; i<8; ++i){
        int actual = matrix[x][y];
        int next = matrix[x+xCambio[i]][y+yCambio[i]];
        visited[x][y] = 1;
        
        if(!actual) continue;
        if(!next) continue;
        if(x+xCambio[i]>=matrix[0].size() || x+xCambio[i]<0 || y+yCambio[i]>=matrix.size() || y+yCambio[i]<0) continue;
        if(visited[x+xCambio[i]][y+yCambio[i]]) continue;
        return 1 + func(matrix, visited, x+xCambio[i], y+yCambio[i]);
    }
    return 0;
}

int main()
{
    int n, m, n1, m1;
    cin >> n >> m;

    n1 = n; m1 = m;

    vvi isles;
    

    while(n--){
        vector<int> temp, temp2;
        while(m--){
            int l;
            cin >> l;
            temp.push_back(l);
            temp2.push_back(0);
        }
        visited.push_back(temp2);
        isles.push_back(temp);
    }
    int total = 0;


    for(int i = 0; i<n1; ++i){
        for(int j = 0; j<m1; ++j){
            if(!visited[n1][m1]) total = max(total, func(isles, visited, i,j));
        }
    }
    cout << total;
}