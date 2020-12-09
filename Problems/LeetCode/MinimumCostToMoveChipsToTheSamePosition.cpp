#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;
        for(auto &a : position){
            if (a%2==0) even++;
            else odd++;
        }
        return min(odd, even);
    }
};