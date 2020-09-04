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
    int n, k, total = 0;
    vector<int> prices;
    cin >> n >> k;

    while (n--)
    {
        int x;
        cin >> x;
        prices.push_back(x);
    }

    sort(all(prices));

    for (int x : prices)
    {
        if (k - x >= 0)
        {
            k -= x;
            total++;
        }
        else
        {
            cout << total;
            break;
        }
    }
}
