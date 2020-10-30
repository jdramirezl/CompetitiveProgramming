#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ld long double
#define ms(ar, val) memset(ar, val, sizeof ar)

using namespace std;

int main()
{
    cout.precision(20);

    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if( a == b ){
            cout << 0 << "\n";
        }
        else{
            int dif  = abs(a-b);
            if(dif <= 10){
                cout << 1 << "\n";
            }
            else{
                int moves = 0;
                for(int i = 10; i>=1; --i){
                    if (dif/i>0){
                        moves += dif/i;
                        dif %= i;
                    }
                }
                cout << moves << "\n";
            }
        }
    }
}