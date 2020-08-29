#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ld long double
#define ms(ar, val) memset(ar, val, sizeof ar)

using namespace std;

void brackets()
{
    int n;
    cin >> n;
    while (n--)
    {
        unordered_map<char, int> prices;
        int k;
        cin >> k;
        while (k--)
        {
            char c;
            cin >> c;
            cin >> prices[c];
        }

        cin >> k;
        string line;
        int total = 0;

        getchar();

        while (k--)
        {
            getline(cin, line);
            for (char &c : line)
            {
                total += prices[c];
            }
        }

        string cents = "";
        if ((total % 100) < 10)
            cents += "0" + to_string(total % 100);
        else
            cents = to_string(total % 100);

        cout << (total / 100) << "." << cents << "$"
             << "\n";
    }
}

int main()
{
    brackets();
}