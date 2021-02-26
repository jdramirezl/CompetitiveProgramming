#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, players, snl, rolls, start, finish, roll, i;
    unordered_map<int, int> move;
    cin >> cases;
    while (cases--){
        cin >> players >> snl >> rolls;
        while(snl--){
            cin >> start >> finish;
            move[start] = finish;
        }

        i = 0;
        while(rolls--){
            i++;
            cin >> roll;
            if(move.count(roll+1) > 0) roll = move[roll+1];
            else roll += 1;

            if(roll >= 100) {cout << "Position of player "<< i << " is " << 100 << "." <<endl; break;}
            else cout << "Position of player "<< i << " is " << roll << "."<< endl;
        }
    }
}