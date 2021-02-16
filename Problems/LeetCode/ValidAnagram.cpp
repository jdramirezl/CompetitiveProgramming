#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> compare;
        
        for(int i = 0; i < s.length(); ++i){
            if(compare.count(s[i]) == 0) compare[s[i]] = 0;
            if(compare.count(t[i]) == 0) compare[t[i]] = 0;
            compare[s[i]] += 1;
            compare[t[i]] -= 1;
        }
        
        for(auto const &[key, value]: compare){
            //cout << "Key: " << key << " Value: " << value << endl;
            if(value != 0) return false;
        }
        
        return true;
    }
};