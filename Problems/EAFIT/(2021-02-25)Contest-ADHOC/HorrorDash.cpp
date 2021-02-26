#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s, m, top, i = 0;
    cin >> n;

    while(n--){
        i++;
        cin >> s;
        top = 0;
        while(s--){
            cin >> m;
            top = max(top, m);
        }
        cout << "Case " <<  i <<": "<< top<< endl;
    }
}