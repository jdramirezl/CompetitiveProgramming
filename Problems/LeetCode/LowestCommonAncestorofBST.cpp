//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root -> val == p -> val) return p;
        if(root -> val == q -> val) return q;
        if(root -> val > p -> val && root -> val < q -> val) return root;
        if(root -> val < p -> val && root -> val > q -> val) return root;
        if(root -> val > p -> val) return lowestCommonAncestor(root -> left, p, q);
        else return lowestCommonAncestor(root -> right, p, q);
    }
};