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
    int coins[] = {1, 5, 10, 25, 50};
    int dp[4][n];
    dp[0][0] = 0; dp[1][0] = 0; dp[2][0] = 0; dp[3][0] = 0; dp[4][0] = 0; 

    forn(1,n){
        for(int j = 0){

        }
    }

    forn(0, 5){
        if(n-coins[i]>=0){
            forn(0,n){

            }
        }
    }
}


int main()
{
    int n;
    while (cin >> n){

    }
}