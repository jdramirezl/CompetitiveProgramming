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

void func(vector<bool> &visited, vector<pair<int, int>> (&matrix)[], int n, int m){
    vector<int> pos(n+1, -1);
    pos[1] = 0;

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i = 0; i<matrix[curr].size(); ++i){
            if(pos[matrix[curr][i].first] == -1){
                pos[matrix[curr][i].first] = pos[curr]+matrix[curr][i].second;
                q.push(matrix[curr][i].first);
            }
        }
    }

    cout << pos[n] << endl;
}

int main()
{
    int n, m, a, b, w;
    cin >> n >> m;
    vector<pair<int, int>> matrix[n+1];
    vector<bool> visited(n+1, false);

    for(int i = 0; i<m; ++i){
        cin >> a >> b >> w;
        matrix[a].push_back(make_pair(b, w));
        matrix[b].push_back(make_pair(a, w));
    }

    
}