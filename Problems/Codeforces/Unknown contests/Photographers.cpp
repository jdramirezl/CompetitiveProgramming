#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n, d, a, b;
    cin >> n >> d;
    cin >> a >> b;
    set<pair<int, int>> clients;
    vector<int> finals;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int var = a * x + y * b;
        if (var <= d)
        {
            clients.insert({a * x + y * b, i + 1});
        }
    }

    for (pair<int, int> j : clients)
    {
        if (d - j.first >= 0)
        {
            d -= j.first;
            finals.push_back(j.second);
        }
        else
        {
            break;
        }
    }

    cout << finals.size() << endl;
    for (int final : finals)
    {
        cout << final << " ";
    }

    return 0;
}