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
    map<int, int> ans;
    
    void aux(TreeNode* root, int level) {
        if(!root) return;
        
        ans[level] = root -> val;
        aux(root -> left, level + 1);
        aux(root -> right, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        aux(root, 0);
        
        vector<int> anss(ans.size(), 0);
        
        for(int i = 0; i<ans.size(); ++i) anss[i] = ans[i];
        
        return anss;
    }
};