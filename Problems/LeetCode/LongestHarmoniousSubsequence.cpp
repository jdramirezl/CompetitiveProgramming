#include <bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << x << endl;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;

        int total = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(freq.count(nums[i]) == 0) freq[nums[i]] = 0;
            freq[nums[i]] += 1;
            
            if(freq.count(nums[i]-1) > 0){
                total = max(total, freq[nums[i]] + freq[nums[i]-1]);
            }
        }
        
        return total;
    }
};