#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define formap(map) for (const auto &[key, value] : map)
#define ms(ar, val) memset(ar, val, sizeof ar)
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    int n, k, total = 0, lu, impor;
    cin >> n >> k;
    vector<int> importants;

    for (int i = 0; i < n; ++i){
        cin >> lu;
        cin >> impor;

        if (impor == 0){
            total += lu;
        }
        else{
            importants.push_back(lu);
        }
    }

    sort(all(importants), greater<int>());

    for (int i = 0; i < importants.size(); ++i){
        if (i < k){
            total += importants[i];
        }
        else{
            total -= importants[i];
        }
    }

    cout << total << "\n";
}
