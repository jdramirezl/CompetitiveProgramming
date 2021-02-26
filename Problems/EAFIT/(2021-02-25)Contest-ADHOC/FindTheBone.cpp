#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, pos = 1, temp, temp2;
    cin >> n >> m >> k;
    unordered_set<int> holes;

    while(m--){
        cin >> temp;
        holes.insert(temp);
    }

    while(k--){
        cin >> temp >> temp2;
        if(holes.count(pos) > 0) break;
        if (temp == pos){
            pos = temp2;
        }
        else if(temp2 == pos){
            pos = temp;
        }
    }

    cout << pos;
}