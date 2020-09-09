#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(x, n) for (int i = x; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define allgreater(v) v.begin(), v.end(), greater<int>()
#define formap(map) for (const auto &[key, value] : map)
#define ms(ar, val) memset(ar, val, sizeof ar)
#define INF 10000000
typedef long long ll;
typedef long double ld;

using namespace std;

int dp(int n){
    int pos = 0;
    int coins[] = {1, 5, 10, 25, 50};
    int dp[5][n];

    fill(*dp, *dp + 5*n, 0);
    for(int i = 0; i<n; ++i){
        dp[0][i] = 1;
    }

    for(int i = 1; i<5; ++i){
        if(coins[i] <= n){
            pos++;
            dp[i][coins[i]-1] = 1 + dp[i-1][coins[i]-1];

            for(int y = 0; y<coins[i]-1; ++y){
                dp[i][y] += dp[i-1][y];
            }

            for(int j = coins[i]; j<n; ++j){
                dp[i][j] += (dp[i-1][j]+dp[i][j-coins[i]]);
            }
        }
    }

    return dp[pos][n-1];

}


int main()
{
    int n;
    string num;
    while (getline(cin, num) && !num.empty()){
        n = stoi(num);
        cout << dp(n) << "\n";
    }
    
}
