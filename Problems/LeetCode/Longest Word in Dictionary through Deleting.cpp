#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int i, j;
        bool found;
        char curr;
        string longest;
        for(const auto &word: d){
            i = 0; j = 0;
            while(i < word.length()){
                found = false;
                curr = word[i];
                while(j < s.length()){
                    if(curr == s[j]){
                        found = true;
                        j++;
                        break;
                    }
                    j++;
                }
                if(found) i++;
                else break;
            }
            if(found){
                if(word.length() > longest.length()) longest = word;
                else if(word.length() == longest.length() && word < longest) longest = word;
            }
        }
        return longest;
    }
};