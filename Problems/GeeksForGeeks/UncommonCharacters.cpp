//https://practice.geeksforgeeks.org/problems/uncommon-characters4932/1
<<<<<<< HEAD
// Time complexity
=======
// Time complexity: O((n+m)logn)
>>>>>>> 63ea76935ce094a57801ee067e9717a10a020c28

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Checks characters that are not common in both strings
// Can be converted to O(n+m) if we dont use a set for order
string UncommonChars(string A, string B){
            unordered_map<char, int> la;
            unordered_map<char, int> lb;
            set<char> s;
            string ab = "";

            for(char x : A) la[x]++;

            for(char y: B) lb[y]++;

            for(char x : A) if(lb.count(x) == 0) s.insert(x);

            for(char y : B) if(la.count(y) == 0) s.insert(y);

            if(s.size() == 0) return "-1";

            for(const auto &x: s) ab += x;

            return ab;
        }
