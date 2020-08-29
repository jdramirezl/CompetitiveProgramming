#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ld long double
#define ms(ar, val) memset(ar, val, sizeof ar)

using namespace std;

bool op(char open)
{
    return open == '(' || open == '[' || open == '{';
}

bool equals(char open, char closes)
{
    return open == '(' && closes == ')' || open == '[' && closes == ']' || open == '{' && closes == '}';
}

void brackets()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        stack<char> open;
        string a;
        cin >> a;
        bool valid = true;
        for (char &j : a)
        {
            if (op(j))
            {
                open.push(j);
            }
            else
            {
                if (!open.empty() && equals(open.top(), j))
                {
                    open.pop();
                }
                else
                {
                    valid = false;
                    break;
                }
            }
        }

        if (valid && open.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    brackets();
}