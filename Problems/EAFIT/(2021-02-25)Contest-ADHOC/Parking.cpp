#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, small = 100, big = -1, temp;
    cin >> n;

    while(n--){
        cin >> m;
        small = 100; big = -1;
        while(m--){
            cin >> temp;
            small = min(small, temp);
            big = max(big, temp);
        }
        cout << (big-small)*2 << endl;
    }
}