#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ld long double
#define ms(ar, val) memset(ar, val, sizeof ar)

using namespace std;

void editor()
{
    int n, va = 0;
    bool up = false;
    string path;
    stack<char> steps;
    cin >> n >> path;
    for (int i = 0; i < n; ++i)
    {
        if (path.at(i) == 'D')
        {
            if (steps.empty())
            {
                up = false;
                va++;
                steps.push('D');
            }
            else if (up)
            {
                steps.pop();
            }
            else
            {
                steps.push('D');
            }
        }
        else
        {
            if (steps.empty())
            {
                up = true;
                steps.push('U');
            }
            else if (!up)
            {
                steps.pop();
            }
            else
            {
                steps.push('U');
            }
        }
    }
    cout << va;
}

int main()
{
    editor();
}