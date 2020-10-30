//https://leetcode.com/problems/buddy-strings/
// T

#include <iostream>
#include <bits/stdc++.h>
#define D(x) cout << #x << " = " << x << endl;

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {


        if(A.length()>B.length()||B.length()>A.length()) return false;

        string a = "", b = "";
        int n = 0, mini = min(A.length(), B.length()), found = 0;
        unordered_set<char> letras;

        for(int i = 0; i<mini; ++i){
            if(letras.count(A[i]) == 0) letras.insert(A[i]);
            else found = 1;



            if (A[i] != B[i]) {
                n++;
                a += A[i];
                b += B[i];
            }
        }

        if(n == 0 && found == 0 || n > 2) return false;
        if(n == 0 && found == 1) return true;

        return (a[0] == b[1] && a[1] == b [0]) ;

    }
};
