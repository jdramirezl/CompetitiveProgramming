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
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int left = aux(root -> left, 0, root -> val, root -> val);
        int right = aux(root -> right, 0, root -> val, root -> val);
        return max(left, right);
    }
    
    int aux(TreeNode *node, int dif, int big, int small){
        if (!node) return dif;
        if(node -> val > big) big = node -> val;
        else if (node -> val < small) small = node -> val;
        
        if(abs(big-small) > dif) dif = abs(big-small);
        
        return max(aux(node -> left, dif, big, small), aux(node -> right, dif, big, small));
    }
    
};