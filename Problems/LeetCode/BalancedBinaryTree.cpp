// https://leetcode.com/problems/balanced-binary-tree/submissions/
// O(n) n -> number of nodes

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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int left = auxBalanced(root -> left, 0);
        int right = auxBalanced(root -> right, 0);
        
        if(left == INT_MAX || right == INT_MAX) return false;
        return abs(left-right) <= 1;
    }
    
    int auxBalanced(TreeNode *node, int height){
        if(!node) return height;
        
        int left = auxBalanced(node -> left, height);
        int right = auxBalanced(node -> right, height);
        
        if(left == INT_MAX || right == INT_MAX) return INT_MAX;
        
        if(abs(left-right) <= 1) return max(left, right) + 1;
        else return INT_MAX;
    }
};