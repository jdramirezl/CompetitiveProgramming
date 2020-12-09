//https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root) {
        change(root);
        return root;
    }
    
    void change(TreeNode *node){
        if(!node) return;

        change(node -> left);
        change(node -> right);
        TreeNode *temp = node -> left;
        node -> left = node -> right;
        node -> right = temp;
    }
};