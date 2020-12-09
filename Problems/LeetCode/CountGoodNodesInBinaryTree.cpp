//https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return auxGood(root, root -> val);
    }
    
    int auxGood(TreeNode *node, int big){
        if(!node) return 0;
        if (node -> val < big) return auxGood(node -> right, big) + auxGood(node -> left, big);
        else return 1 + auxGood(node -> right, node -> val) + auxGood(node -> left, node -> val);
        
    }
};