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

int k, n;
const int MAXN = 100;
int dp[26][MAXN];
vector<vector<char>> real_options;

bool maxSize(vector<char> i1, vector<char> i2){ 
    return (i1.size() < i2.size());
}

int dp_func(){
    

    return 0;
}


int main(){
    int maxFrec;
    cin >> n;
    unordered_map<char, int> x;
    vector<unordered_map<char, int>> options (n, x);
    string a, b, c;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 26; ++j){
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i<n; ++i){
        cin >> a >> b >> c;
        cout << a << " " << b << " " << c << endl;
        maxFrec = 0;
        for(int j = 0; j < a.size(); ++j){
            options[i][a[j]]++;
            maxFrec = max(maxFrec, options[i][a[j]]);
        }

        for(int j = 0; j < b.size(); ++j){
            options[i][b[j]]++;
            maxFrec = max(maxFrec, options[i][b[j]]);
        }

        for(int j = 0; j < c.size(); ++j){
            options[i][c[j]]++;
            maxFrec = max(maxFrec, options[i][c[j]]);
        }
        
        vector<char> temp;
        for(const auto &map: options[i]){
            if(map.second == maxFrec) temp.push_back(map.first);
        }
        real_options.push_back(temp);
    }

    cin >> k;
    sort(real_options.begin(), real_options.end(), maxSize);
    cout << dp_func() << endl;
}   