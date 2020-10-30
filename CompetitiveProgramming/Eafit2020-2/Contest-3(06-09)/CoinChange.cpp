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
    int dp[n];

    for(int i = 0; i<n; ++i){
        dp[i]  = 1;
    }

    for(int i = 1; i<5; ++i){
        if(coins[i] <= n){
            dp[coins[i]-1] += 1;

            for(int j = coins[i]; j<n; ++j){
                dp[j] += dp[j-coins[i]];
            }
        }
    }

    return dp[n-1];

}


int main(){
    int n;
    string num;
    while (getline(cin, num) && !num.empty()){
        n = stoi(num);
        cout << dp(n) << "\n";
    }
}
