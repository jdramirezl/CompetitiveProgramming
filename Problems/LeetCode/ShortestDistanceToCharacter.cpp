#include <bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << x << "\n";

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.length(), INT_MAX);
        int len = s.length(), lastC = -1;
        
        for(int i = 0; i < len; ++i){
            if(s[i] != c && lastC != -1) {
                ans[i] = i - lastC;
            }
            else if(s[i] == c) {
                lastC = i;
            }
        
        }
        

        
        lastC = -1;
        for(int i = len - 1; i >= 0; --i){
            if(s[i] != c && lastC != -1){
                if(lastC - i < ans[i]) {
                    ans[i] = lastC - i;
                }
            }
            else if(s[i] == c) {
                lastC = i;
                ans[i] = 0;
            }
        }

        
        return ans;
    }
};