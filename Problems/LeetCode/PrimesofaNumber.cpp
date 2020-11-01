// https://leetcode.com/problems/count-primes/
// TimeComplexity: O(n^2)
// Can be further improved with the algoritm for this. Array cleaning

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n, vector<int> &nums){
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]*nums[i] > n) break;
            if(n%nums[i] == 0) return false; 
        }
        
        return true;
    }
    
    int countPrimes(int n) {
        vector<int> primes;
        
        if(n > 2){
            primes.push_back(2);
            for(int i = 3; i < n; i += 2){
                if (isPrime(i, primes))  primes.push_back(i);
            }
        }
        
        return primes.size();
    }
};