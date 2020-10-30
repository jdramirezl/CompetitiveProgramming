// https://leetcode.com/problems/non-decreasing-array/
// Time complexity:  O(n)

#include <bits/stdc++.h>
#define forn(x, n) for (int i = x; i < (int)n; ++i)

using namespace std;

class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            int n = 0, size = nums.size(), high = nums[0], me, ma, mev, mav;

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

            cout << ma << " " << me << endl;

            //Removing first
            cout << "First"<< endl;
            nums[ma] = mev;
            for(int i = 0; i<nums.size()-1; ++i){
                cout << nums[i] << " " << nums[i+1]<< endl;
                if(nums[i] > nums[i+1]) {
                    nf = true;
                    break;
                }
            }

            //removing second
            cout << "Second"<< endl;
            nums[me] = mav;
            nums[ma] = mav;
            for(int i = 0; i<nums.size()-1; ++i){
                cout << nums[i] << " " << nums[i+1]<< endl;
                if(nums[i] > nums[i+1]) {
                    ns = true;
                    break;
                }
            }

            cout << ns << " " << nf;

            return !(nf && ns);
        }
};
