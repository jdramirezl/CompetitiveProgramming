//https://leetcode.com/problems/max-number-of-k-sum-pairs/submissions/

#include <bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << x << endl;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int total = 0;
        unordered_map<int, int> adds;
        for(const auto &a: nums){
            if (adds.count(a) == 0) adds[a] = 1;
            else adds[a] += 1;
        }
        
        for(const auto &a: nums){
            if(adds[a] <= 0) continue;
            
            if (adds[k-a] == 1) {
                if(a == k-a) continue;
                else{
                    D("In first with")
                    D(a)
                    total++;
                    adds[a] -= 1;
                    adds[k-a] -= 1;
                }
            }
            else if(adds[k-a] >  1){
                if(a == k-a) {
                    D("In second with")
                    D(a)
                    total += 1;
                    adds[k-a] -= 2;
                }
                else{
                    D("In third with")
                    D(a)
                    total++;
                    adds[a] -= 1;
                    adds[k-a] -= 1;
                }
                /*
                D(adds[k-a])
                D(k-a)
                D(adds[a])
                */
            }
        }
        return total;
    }
};