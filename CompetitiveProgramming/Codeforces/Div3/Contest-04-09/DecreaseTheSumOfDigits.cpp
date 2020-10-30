#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define allgreater(v) v.begin(), v.end(), greater<int>()
#define formap(map) for (const auto &[key, value] : map)
#define ms(ar, val) memset(ar, val, sizeof ar)
typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    ll t, n, s;
    cin >> t;

    while(t--){
        cin >> n >> s;

        if(n <= s){
            cout << 0 << "\n";
        }
        else{

            //first sum
            ll temp = n, sum = 0, digits = 0;
            while (temp != 0){
                sum += temp%10;
                digits++;
                temp /= 10;
            }

            ll moves = 0, round = 0;
            while(sum > s){
                round++;
                ll powe = pow(10, round);
                n += (powe-(n%powe));
                moves += (powe-(n%powe));
                sum += powe - (powe -(n%powe));
            }
            cout << moves << "\n";
        }
    }
}