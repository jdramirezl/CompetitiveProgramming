#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ld long double
#define ms(ar, val) memset(ar, val, sizeof ar)

using namespace std;

void brackets()
{
    cout << fixed << setprecision(4);
    int n;
    cin >> n;
    getchar();
    getchar();
    for (int i = 0; i < n; ++i)
    {

        string s;
        double tot = 0;
        map<string, int> trees;

        while (getline(cin, s) && !s.empty())
        {
            tot++;
            trees[s] += 1;
        }

        for (auto const &y : trees)
        {
            cout << y.first << " " << ((y.second * 1.0) * 100.0) / tot << "\n";
        }

        if (i < n - 1)
        {
            cout << "\n";
        }
    }
}

int main()
{
    brackets();
}