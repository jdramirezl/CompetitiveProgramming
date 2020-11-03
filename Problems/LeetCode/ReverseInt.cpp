// https://leetcode.com/problems/reverse-integer/
// O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        
        if (x<0) if(x < pow(-2, 31) + 1) return 0;
        else if(x >  (pow(2, 31) - 1)) return 0;
        
        if(x < 0) {
            neg = true; 
            x *= -1;
        }
        
        long long num = 0;

        while(x){
            int temp = x%10;
            x /= 10;
            num += temp;
            num *= 10;
        }
        
        num /= 10;
        
        if (neg) {
            num *= -1;
            if(num < pow(-2, 31)) return 0;
        }
        else {
            if(num >  (pow(2, 31)-1)) return 0;
        }
        
        return (int) num;
    }
};