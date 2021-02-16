// A Leetcode treenode

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
        int aux(TreeNode *root, int total){
            if(!root) return total;
            root -> val = aux(root -> right, total) + root -> val;
            return aux(root -> left, root -> val);
        }

        TreeNode *convertBST(TreeNode* root) {
            aux(root, 0);
            return root;
        }
};