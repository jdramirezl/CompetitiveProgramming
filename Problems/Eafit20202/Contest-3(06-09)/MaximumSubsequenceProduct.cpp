#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(x, n) for (int i = x; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define allgreater(v) v.begin(), v.end(), greater<int>()
#define formap(map) for (const auto &[key, value] : map)
#define ms(ar, val) memset(ar, val, sizeof ar)
typedef long long ll;
typedef long double ld;

using namespace std;

ll solution(vector<ll> nums){
    ll best = nums[0], sum = nums[0], negs = 0;
    bool zero = false;
    stack<ll> zeros;

    forn(1, nums.size()){
        if(nums[i] < 0){
            negs++;
        }

        if(nums[i] == 0){
            zeros.push(sum);
            zero = true;
        }

        sum = max(nums[i], nums[i] * sum);
        best = max(sum, best);
    }

    return best;
}

int main(){
    ll n;

    while (cin >> n){
        if(n != -1){
            vector<ll> nums;
            nums.push_back(n);
            while (cin >> n && n != -999999){
                nums.push_back(n);
            }
            cout << solution(nums) << "\n";
            n = -1;
        }
        else{
            break;
        }

    }
}