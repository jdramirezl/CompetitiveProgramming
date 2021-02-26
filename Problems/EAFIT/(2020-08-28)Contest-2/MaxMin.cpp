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

int problem()
{
    int n, k, num, mini, x, y;
    cin >> n >> k;
    vector<int> nums;
    unordered_map<int, int> repetitions;

    while (n--)
    {
        cin >> num;
        nums.push_back(num);
    }

    sort(all(nums));
    mini = nums[nums.size() - 1];

    for (int i = 0; i <= (nums.size() - k); ++i)
    {
        x = (nums[i]);
        y = nums[i + k - 1];

        mini = min((y - x), mini);
    }

    return mini;
}

int main()
{
    cout << problem();
}