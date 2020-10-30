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
    
    long long t, a, b, x, y, n, c1, c2;
    cin >> t;
    
    while(t--){
        cin >> a >> b >> x >> y >> n;
    
        //A
        if(n <= a-x ){
            c1 = ((a-n)*b);
        }
        else{
            long long cabe =  (b-y);
            long long resto = n - (a-x);
            if(resto > cabe){
                c1 = ( (a - (a-x)) * (b - (cabe)));
            }
            else{
                c1 = ( (a - (a-x)) * (b - (resto)));
            }
    
        }
    
        //B
        if(n <= b-y ){
            c2 = ((b-n)*a);
        }
        else {
            long long cabe =  (a-x);
            long long resto = n - (b-y);
            if(resto > cabe){
                c2 = ((b - (b - y)) * (a - (cabe)));
            }
            else{
                c2 = ((b - (b - y)) * (a - (resto)));
            }
    
        }
    
        if(c1 <= 0){
            cout << c2 << "\n";
        }
        else if( c2 <= 0){
            cout << c1 << "\n";
        }
        else{
            cout << min(c1, c2) << "\n";
        }
    
    }
}