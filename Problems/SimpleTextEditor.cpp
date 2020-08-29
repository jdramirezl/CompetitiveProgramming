#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ld long double
#define ms(ar, val) memset(ar, val, sizeof ar)

using namespace std;

void editor()
{
    int q, t;
    string w;
    stack<string> operations;
    string starter = "";
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> w;
            operations.push(starter);
            starter.append(w);
            break;
        case 2:
            cin >> t;
            operations.push(starter);
            starter.erase(starter.size() - t, t);
            break;
        case 3:
            cin >> t;
            cout << starter.at(t - 1) << endl;
            break;
        case 4:
            starter = operations.top();
            operations.pop();
            break;
        }
    }
}

int main()
{
    editor();
}