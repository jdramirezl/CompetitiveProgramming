#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ld long double
#define ms(ar, val) memset(ar, val, sizeof ar)

using namespace std;

void Chocolate()
{
    int n;
    cin >> n;
    int chocos[n];

    //Recibir chocolates
    for (int i = 0; i < n; ++i)
    {
        cin >> chocos[i];
    }

    int d, m, total = 0, window = 0;
    cin >> d >> m;

    //Create first window
    for (int i = 0; i < m; ++i)
    {
        window += chocos[i];
    }

    if (window == d)
    {
        total++;
    }

    //Check windows
    for (int i = m; i < n; ++i)
    {
        window += (chocos[i] - chocos[i - m]);
        if (window == d)
        {
            total++;
        }
    }

    cout << total;
}

int main()
{
    Chocolate();
}