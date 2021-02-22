#include <bits/stdc++.h>
using namespace std;


// SUBSTRING IS VERY SLOW, A BETTER ALTERNATIVE IS TO MARK INVALID PARENTHESES WITH A MARKER AND 
// CREATE A NEW STRING IGNORING THE MARKED PARENTHESES
class Solution {
public:
    #define pci pair<char, int>
    
    struct CustomCompare{
        bool operator()(const pci& first, const pci& second){
            return first.second > second.second;
        }
    };
    
    string minRemoveToMakeValid(string s) {
        priority_queue<pci, vector<pci>, CustomCompare> p;
        cout << s.length() << endl;
        
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(') p.push(make_pair('(', i));
            else if (s[i] == ')'){
                if(!p.empty()) p.pop();
                else {
                    if(i == 0) s = s.substr(1, s.length());
                    else s = s.substr(0, i) + s.substr(i+1, s.length());
                    i--;
                }
            }
        }
        

        if(!p.empty()){
            int i, m = 0;
            while(!p.empty()){
                i = p.top().second;
                i -= m;
                p.pop();
                s = s.substr(0, i) + s.substr(i+1, s.length());
                m++;
            }
        }
        
        return s;
    }
    
};

// ALTERNATIVE
class Alternative {
public:
    string minRemoveToMakeValid(string s) {
        int pending = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && pending == 0) {
                s[i] = '*';
            } else if (s[i] == ')') {
                pending--;
            } else if (s[i] == '(') {
                pending++;
            }
        }
        
        pending = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(' && pending == 0) {
                s[i] = '*';
            } else if (s[i] == '(') {
                pending--;
            } else if (s[i] == ')') {
                pending++;
            }
        }
        
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                ans.append(1, s[i]);
            }
        }
        
        return ans;
    }
};

