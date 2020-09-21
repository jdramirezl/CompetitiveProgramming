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

int main()
{
    int n, zero = 0, one = 0, two = 0;
    cin >> n;
    vector<int> days(n);
    vector<vector<int>> dp(3, vector<int>(n+1));
    dp[0][0] = 0; dp[1][0] = 0; dp[2][0] = 0;

    forn(0, n) cin >> days[i];

    forn(1, n+1){ //1 3 2 0
        //0
        if(days[i-1] == 0){
            dp[0][i] = 1 + min(dp[0][i-1], min(dp[1][i-1], dp[2][i-1]));
            dp[1][i] = INF;
            dp[2][i] = INF;
        }

        //1 contest
        if(days[i-1] == 1) {
            dp[0][i] = 1 + min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1]));
            dp[2][i] = INF;
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
        }

        //2 gym
        if(days[i-1] == 2) {
            dp[0][i] = 1 + min(dp[0][i-1], min(dp[1][i - 1], dp[2][i - 1]));
            dp[1][i] = INF;
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
        }

        //3
        if(days[i-1] == 3) {
            dp[0][i] = 1+ min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1]));
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
        }
    }

    cout << min(dp[0][n], min(dp[1][n], dp[2][n]));
}
