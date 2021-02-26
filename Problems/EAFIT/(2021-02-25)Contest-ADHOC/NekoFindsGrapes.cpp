#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, ek = 0, ok = 0, ec, oc, total = 0, temp;
    cin >> n >> m;

    while(n--){ 
        cin >> temp;
        if(temp%2==0)ek++;
        else ok++;
    }
    
    while(m--){ 
        cin >> temp;
        
        if(temp%2==0 && ok > 0){
            total++; 
            ok--;
        }
        else if(temp%2!=0 && ek > 0) {
            total++; 
            ek--; 
        }
    }

    cout << total << endl;
}