#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define formap(map) for (const auto &[key, value] : map)
#define ms(ar, val) memset(ar, val, size)
typedef long long ll;
typedef long double ld;

#define INF 1000000

using namespace std;

#include <iostream>
using namespace std;

string convertToTitle(int n) {
        string result;
        while (n) {
            result.push_back('A' + (n - 1) % 26), n = (n - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }

int main() {
	//for(int i = 0; i<100; ++i)convertToTitle(i);

	convertToTitle(52);
	convertToTitle(703);

	return 0;
}
