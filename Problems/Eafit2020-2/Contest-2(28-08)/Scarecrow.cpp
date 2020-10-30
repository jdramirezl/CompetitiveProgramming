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

int main()
{
    int T, n, cases;
    string s;
    cin >> T;
    cases = T;
    while (T--)
    {
        int total = 0;
        cin >> n >> s;
        for (int i = 0; i < n; ++i)
        {
            if (s.at(i) == '.')
            {
                total++;
                i += 2;
            }
        }
        cout << "Case " << (cases - T) << ": " << total << "\n";
    }
}