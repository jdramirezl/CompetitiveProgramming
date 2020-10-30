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
    double problems, numWins = 0, numLoss = 0;
    cin >> problems;

    double winner[(int)problems];
    double loser[(int)problems];

    for (int i = 0; i < problems; i++)
    {
        cin >> winner[i];
    }

    for (int i = 0; i < problems; i++)
    {
        cin >> loser[i];
    }

    for (int i = 0; i < problems; ++i)
    {
        numWins += winner[i] > loser[i];
        numLoss += winner[i] < loser[i];
    }

    if (numWins > numLoss)
    {
        cout << 1 << endl;
    }
    else if (numWins == numLoss && numWins == 0 || !numWins)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ceil((numLoss + 1) / numWins) << endl;
    }
}