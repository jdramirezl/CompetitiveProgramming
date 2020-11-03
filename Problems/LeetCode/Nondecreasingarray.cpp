// https://leetcode.com/problems/non-decreasing-array/
// Time complexity:  O(n)

#include <bits/stdc++.h>
#define forn(x, n) for (int i = x; i < (int)n; ++i)

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = 0, size = nums.size(), high = nums[0], me =-1, ma, mev, mav;

        if(size <= 2) return true;

        //Find breaking point
        for(int i = 0; i<nums.size()-1; ++i){
            if(nums[i] > nums[i+1]) {
                me = i;
                mev = nums[i];
                ma = i+1;
                mav = nums[i+1];
                break;
            }
        }
        
        bool nf = false, ns = false;
        
        if(me != -1){
            nums[ma] = mev;
            for(int i = 0; i<nums.size()-1; ++i){
                if(nums[i] > nums[i+1]) {
                    nf = true;
                    break;
                }
            }
            
            nums[me] = mav;
            nums[ma] = mav;
            for(int i = 0; i<nums.size()-1; ++i){
                if(nums[i] > nums[i+1]) {
                    ns = true;
                    break;
                }
            }
            
        }
        
        return !(nf && ns);
    }
};
