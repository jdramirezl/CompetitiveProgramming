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
    int n, k, num, l, final = 0, total = 0;
    cin >> n >> k;
    l = n;
    vector<int> prices;

    while (n--)
    {
        cin >> num;
        prices.push_back(num);
    }

    sort(all(prices), greater<int>());

    for (int i = 0; i < (l / k); i++)
    {
        for (int j = 0; j < k; ++j)
        {
            total += ((i + 1) * prices[final]);
            final += 1;
        }
        n = i + 1;
    }

    for (int i = final; i < prices.size(); ++i)
    {
        total += (n + 1) * prices[i];
    }

    cout << total;
}