//https://leetcode.com/problems/third-maximum-number/
// Time complexity: O(n)

#include <iostream>
#include <bits/stdc++.h>
#define D(x) cout << #x << " = " << x << endl;

using namespace std;


// Improvements with treeset - not logn as it will always have 3 items (3 biggest)

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        int f=0, s=0, t=0, size = nums.size();
        
        for(int x : nums){
            
            
            if((x == f || x == s || x == t) && x != 0) {
                size--;
            }
            
            if(x > f || x < 0 && f == 0){
                t = s;
                s =  f;
                f = x;
            }
            else if((x > s || x < 0 && s == 0) && x != f ){
                t = s;
                s = x;
            }
            else if((x > t || x < 0 && t == 0)&& x != s && x != f){
                t = x;
            }
            cout << "size" << endl;
            cout << size << endl;
            
        }
        cout << "xd" << endl;
        cout << f << endl;
        cout << s << endl;
        cout << t << endl;
        if(size < 3) return f;
        else return t;
    }
};