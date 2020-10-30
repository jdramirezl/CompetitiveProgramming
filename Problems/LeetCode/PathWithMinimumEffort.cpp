// https://leetcode.com/problems/path-with-minimum-effort/
// Time complexity: O((v+e)*logn) v+e: nodes and edges, logn: insert in treeset

#include <iostream>
#include <bits/stdc++.h>
#define D(x) cout << #x << " = " << x << endl;

using namespace std;

class Solution {
public:

    //Ignore, debug method
    static void print(const vector<vector<int>>& xd){
        for(auto &a : xd){
            for(auto &b: a){
                cout << setw(4) << b << " ";
            }
            cout << endl;
        }
    }

    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> d(heights.size(), vector<int>(heights[0].size(), -1));

        int rows = heights.size();
        int cols = heights[0].size();
        set<int> alv;
        queue<pair<int, int>> q;


        if(rows == 1 && cols == 1) return 0;

        d[0][0] = heights[0][0];

        if(rows > 1){
            d[1][0] = abs(heights[0][0] - heights[1][0]);
            q.push(make_pair(1, 0));
        }

        if(cols > 1){
            d[0][1] = abs(heights[0][0] - heights[0][1]);
            q.push(make_pair(0, 1));
        }


        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();

            for(int i = 0; i<4; ++i){
                int nx = x[i] + curr.first;
                int ny = y[i] + curr.second;


                if(nx >= rows || nx < 0 || ny >= cols || ny < 0) continue;

                int dif = max(d[curr.first][curr.second],abs(heights[curr.first][curr.second]  - heights[nx][ny]));
                if(nx == rows-1 && ny ==cols-1) alv.insert(dif);

                if(d[nx][ny] == -1){
                    d[nx][ny] =  max(d[curr.first][curr.second], abs(heights[curr.first][curr.second]  - heights[nx][ny]));
                    q.push(make_pair(nx, ny));
                }
                else if(dif < d[nx][ny]){
                    d[nx][ny] = dif;
                    q.push(make_pair(nx, ny));
                }
            }
        }


        int var;
        if(!alv.empty())var = *next(alv.begin(),0);
        else var = d[rows-1][cols-1];


        return var;
    }
};
