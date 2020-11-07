// https://leetcode.com/problems/valid-mountain-array/
// Time complexity: O(n)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool increase = true;
        int inc = 0, dec = 0;
        
        if(A.size() == 0) return false;
        
        for(int i = 0; i < A.size()-1; ++i){
            if(A[i] == A[i+1]) return false;
            
            if(increase){
                if(A[i] < A[i+1]) inc++;
                else{
                    increase = false;
                    dec++;
                }
            }
            else{
                if(A[i] > A[i+1]) dec++;
                else return false;  
            }
        }
        
        return (inc > 0 && dec > 0);
    }
};