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

void problem()
{
    int n, m, t, T, x, cost, nbuses, mini, maxi, temp; //t (°per region), T (max ° per bus), cost (cost per bus)
    long long total = 0;
    cin >> n >> m;
    while (n--)
    {
        cin >> t >> T >> x >> cost;

        if (T >= (t + m))
        {
            total = cost;
        }
        else
        {

            mini = cost + (m * x);

            if (T - t == 0)
            {
                temp = mini;
            }
            else
            {
                if (m % (T - t) > 0)
                {
                    maxi = min(cost * ((m / (T - t)) + 1), cost * (m / (T - t)) + x * ((m % (T - t)) + (T - t))); //1 - todos
                }
                else
                {
                    maxi = cost * ((m / (T - t)));
                }

                temp = min(maxi, mini);
            }
        }

        total += temp;
    }
    cout << total;
}

int main()
{
    problem();
}