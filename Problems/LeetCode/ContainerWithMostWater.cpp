#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, li = 0, ri = height.size()-1;
        int left = height[li], right = height[ri], base = ri-li;
        for(int i = 0; i<height.size(); ++i){
            if(ri == li) break;
            //cout << "Left: " << left << " Right: " << right; 
            //cout << "\nBase: " << base << endl;
            area = max(min(left, right) * base, area);
            if(left == right){
                ri--;
                right = height[ri];
                if(ri == li) break;
                
                li++;
                left = height[li];
                base--;
            }
            else if(left > right){
                ri--;
                right = height[ri];
            }
            else{
                li++;
                left = height[li];
            }
            base--;
        }
        return area;
    }
};
