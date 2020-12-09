//
//

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> a;
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        aux(root);
        int total = 0;
        cout << "size: " << a.size(); 
        for(auto &xd : a) total += xd;  
        return total;
    }
    
    int aux(TreeNode* node) {
        if(!node) return 0;
        int left = aux(node -> left);
        int right = aux(node -> right);
        a.push_back(abs(left-right));
        return node -> val + left + right;
    }
};