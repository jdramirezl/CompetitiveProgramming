#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    
    void aux(string s, int i){
        if(i >= s.length()){
            ans.push_back(s);
            return;
        }
        
        if(isdigit(s[i])){
            aux(s, i+1);
            return;
        }
        else{
            if(isupper(s[i])){
                string temp = s;
                temp[i] = tolower(s[i]);
                aux(temp, i+1);
                aux(s, i+1);
            }
            else{
                string temp = s;
                temp[i] = toupper(s[i]);
                aux(temp, i+1);
                aux(s, i+1);
            }
        }
        return;
    }
    
    vector<string> letterCasePermutation(string S) {
        aux(S, 0);
        return ans;
    }
};