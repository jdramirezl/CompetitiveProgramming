#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char,char> map = 
    {
        {'E','3'}, 
        {'J', 'L'}, 
        {'L', 'J'}, 
        {'0', 'O'}, 
        {'S','2'}, 
        {'Z', '5'}, 
        {'2','S'},
        {'3', 'E'}, 
        {'5', 'Z'}, 
        };
    string s;
    bool pal = false, ms = false, mp = false; 
    while(true){
        getline(cin, s);
        if(s == "") break;
        int size = s.length();
        pal = true;

        for(int i = 0; i < size; ++i) if (s[i] == '0' || s[i] == 'O') s[i] = 'O';

        for(int i = 0; i <size/2; ++i){
            if (s[i] != s[size-1-i]){
                pal = false;
                break;
            }
        }

        string modified = s;
        int x = 0;
        for(const auto &c: s){
            if(map.count(c)) modified[x] = map[c];
            x++;
        }

        ms = true;
        for(int i = size-1; i >= 0; --i){
            if(s[size-i-1] != modified[i]){
                ms = false;
                break;
            }
        }

        
        if(!pal && !ms) cout << s <<" -- is not a palindrome." << endl;
        else if(pal && !ms) cout << s <<" --  is a regular palindrome." << endl;
        else if(!pal && ms) cout << s <<" --  is a mirrored string." << endl;
        else if(pal && ms) cout << s <<" --   is a mirrored palindrome." << endl;
        cout << endl;
    }
}