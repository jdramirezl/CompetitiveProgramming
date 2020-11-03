// https://leetcode.com/explore/featured/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3518/
// TimeComplexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        
        int maxi = 1, temp = 0;
        bool start = false;
        
        for(int i = 0; i <s.length()-1; ++i){
            
            if(s[i] == s[i+1]){
                if(!start){
                    temp += 2;
                    start = true;
                }
                else temp ++;
            }
            else{
                start = false;
                if(maxi < temp) maxi =temp;
                temp = 0;
            }
        }
        
        if(s.length() == 0) return 0;
        if(maxi < temp) maxi = temp;
        return maxi;
        
    }
};