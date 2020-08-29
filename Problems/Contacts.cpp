#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(x, n) for (int i = x; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define formap(map) for (const auto &[key, value] : map)
#define ms(ar, val) memset(ar, val, sizeof ar)
typedef long long ll;
typedef long double ld;

using namespace std;

int binary(vector<string> contacts, string name, int size)
{
    int first = 0,       // First array element
        last = size - 1, // Last array element
        middle,          // Mid point of search
        position = -1;   // Position of search value
    bool found = false;  // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;                         // Calculate mid point
        if (contacts[middle].substr(0, name.size()) == name) // If value is found at mid
        {
            found = true;
            position = middle;
            break;
        }
        else if (contacts[middle] < name) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }

    if (found)
    {
        int total = 1;

        //for abajo
        for (int i = position + 1; i < contacts.size(); ++i)
        {
            if (contacts[i].substr(0, name.size()) == name)
            {
                total++;
            }
            else
            {
                break;
            }
        }

        //for abajo
        for (int i = position - 1; i >= 0; --i)
        {
            if (contacts[i].substr(0, name.size()) == name)
            {
                total++;
            }
            else
            {
                break;
            }
        }

        return total;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> contacts;

    while (n--)
    {
        string op, name;
        cin >> op >> name;
        if (op == "add")
        {
            contacts.push_back(name);
            sort(all(contacts));
        }
        else
        {
            cout << binary(contacts, name, contacts.size()) << "\n";
        }
    }
}