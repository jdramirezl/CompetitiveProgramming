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

    for (int i = 0; i < n; ++i)
    {
        unordered_map<char, pair<int, int>> hiero;
        hiero['B'] = make_pair(1, 0);
        hiero['U'] = make_pair(10, 0);
        hiero['S'] = make_pair(100, 0);
        hiero['P'] = make_pair(1000, 0);
        hiero['F'] = make_pair(10000, 0);
        hiero['T'] = make_pair(100000, 0);
        hiero['M'] = make_pair(1000000, 0);
        string s;
        cin >> s;
        int total = 0, last = hiero[s.at(0)].first;
        bool inc = false, error = false;

        //Check if increase or decrease
        for (char &c : s)
        {
            if (hiero[c].first > last)
            {
                inc = true;
                break;
            }
            else if (hiero[c].first < last)
            {
                inc = false;
                break;
            }
        }

        //Check quantity and order
        for (char &c : s)
        {
            if (hiero[c].second + 1 > 9)
            {
                error = true;
                break;
            }
            else
            {
                hiero[c].second++;
            }

            if (inc && hiero[c].first < last)
            {
                error = true;
                break;
            }
            else if (!inc && hiero[c].first > last)
            {
                error = true;
                break;
            }

            last = hiero[c].first;
            total += hiero[c].first;
        }

        if (error)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << total << endl;
        }
    }
}

int main()
{
    brackets();
}