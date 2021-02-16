#include <bits/stdc++.h>
using namespace std;

#define D(x, y) cout << #x << " " << x << " " <<#y <<  " " << y << endl;

class Solution {
public:
    int xChange[8] = {-1,-1,-1,0,0,1,1,1};
    int yChange[8] = {-1,0,1,-1,1,-1,0,1};
    
    void print(vector<vector<int>>& grid){
        for(auto &row: grid){
            for(auto &a: row){
                cout << a << " ";
            }
            cout << endl;
        }
        
        cout << endl;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int currx, curry, nextx, nexty, N, M;
        N = grid.size();
        M = grid[0].size();
        
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
        queue<pair<int, int>> q; 
        visited[0][0] = 1;
        
        q.push(make_pair(0,0));
        
        while(!q.empty()){
            currx = q.front().first;
            curry = q.front().second;
            q.pop();
            //cout << "\n";
        // D(currx, curry);
            
            for(int i = 0; i < 8; ++i){
                nextx = currx + xChange[i];
                nexty = curry + yChange[i];
                            
                
                if(nextx >= N || nextx < 0 || nexty >= M || nexty < 0) continue;
                if(grid[nextx][nexty] == 1) continue;
                
                // D(nextx, nexty)   
                
                if(visited[nextx][nexty] == -1){
                    visited[nextx][nexty] = visited[currx][curry] + 1;
                    if(!(nextx == N-1 && nexty == M-1)) q.push(make_pair(nextx, nexty));
                }
                else if((visited[currx][curry] + 1 ) < visited[nextx][nexty]){
                    visited[nextx][nexty] = visited[currx][curry] + 1;
                    if(!(nextx == N-1 && nexty == M-1)) q.push(make_pair(nextx, nexty));
                }
            }
        }
        
    
        return visited[N-1][M-1];
    }
};