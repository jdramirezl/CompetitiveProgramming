//https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> ts;
        
        int a = 0;
        for(const auto &x: nums){
            ts[x].push_back(a);
            a++;
        }
        
        vector<int> ans;
        for(int i = 0; i<nums.size(); ++i){
            if(ts[target-nums[i]].size() > 0){
                if(ts[target-nums[i]].size() > 1){
                    ans = {i, ts[target-nums[i]][1]};
                    break;
                }
                else if(ts[target-nums[i]][0] != i){
                    ans = {i, ts[target-nums[i]][0]};
                    break;
                }
            } 
        }
        
        return ans;
    }
};