// https://leetcode.com/problems/string-to-integer-atoi/submissions/
// O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string abc) {
        bool neg = false, entered = false, start = true, num = false, pos = false;
        unordered_set<char> s = {'0','1','2','3','4','5','6','7','8','9'};
        int a = 0, temp;

        for(auto &c: abc){
            if(c == '+' && start){
                start = false;
                pos = true;
            }
            else if(c == '-' && start){
                start = false;
                neg = true;
            }
            else if(s.count(c) > 0){
                num = true;
                start = false;
                entered = true;
                
                if(!neg) temp = c - 48;
                else temp = (c-48)*-1;

                cout << "temp" << temp << "\n";

                if(!neg && (a > INT_MAX/10 || (a == INT_MAX/10 && temp > 7))) return INT_MAX;

                if(neg && (a < INT_MIN/10 || (a == INT_MIN/10 && temp < -8))) return INT_MIN;

                a = a*10+temp;
            }
            else if((c != ' ' && !entered) || ((neg||pos) && !num)){
                return 0;
            }
            else if(entered){
                break;
            }
        }

        return a;
    }
};