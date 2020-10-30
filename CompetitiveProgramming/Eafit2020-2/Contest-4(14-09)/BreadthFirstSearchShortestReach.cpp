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


void bfs(vector<int> (&matrix)[], int s, int n){
    vector<int> pos(n+1, -1);
    pos[s] = 0;

    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int current = que.front();
        que.pop();
        for(int i = 0; i<matrix[current].size(); ++i){
            if(pos[matrix[current][i]] == -1){
                pos[matrix[current][i]] = pos[current] + 1;
                que.push(matrix[current][i]);
            }
        }
    }


    for(int i = 1; i<pos.size(); ++i){
        if(i != s){
            if(pos[i] == -1){
                cout << pos[i] << " ";
            }
            else {
                cout << pos[i]*6 << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    int q;
    cin >> q;

    for(int i = 0; i<q; ++i){
        int n, m, u, v, s;
        cin >> n >> m;

        vector<int> matrix[n+1];

        for(int j = 0; j<m; ++j){
            cin >> u >> v;
            matrix[u].push_back(v);
            matrix[v].push_back(u);
        }

        cin >> s;

        bfs(reinterpret_cast<vector<int> (&)[]>(matrix), s, n);
    }
}