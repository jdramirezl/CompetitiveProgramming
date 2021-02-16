#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    struct CustomCompare{
        bool operator()(pair<int,int> &p1, pair<int,int> &p2){
            if(p1.first != p2.first){
                return p1.first > p2.first;
            }
            return p1.second > p2.second;
        }
    };

    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, CustomCompare> pq;
        vector<int> ans(k, 0);
        int temp;
        for(int i = 0; i < mat.size(); ++i){
            temp = 0;
            for(int j = 0; j < mat[0].size(); ++j){
                temp += mat[i][j];
            }
            pq.push(make_pair(temp, i));
        }
        
        for(int i = 0; i < k; ++i){
            ans[i] = pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};