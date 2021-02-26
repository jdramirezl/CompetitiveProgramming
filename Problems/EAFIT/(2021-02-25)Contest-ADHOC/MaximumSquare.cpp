#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, temp, base = 1, area_max = 1;
    cin >> n;

    while(n--){
        priority_queue<int> pq;
        cin >> m;
        while(m--){
            cin >> temp;
            pq.push(temp);
        }

        area_max = 1;
        base = 1;
        while(!pq.empty() && pq.top() >= base){
            area_max = base;
            pq.pop();
            base++;
        }
        cout << area_max << endl;
    }
}