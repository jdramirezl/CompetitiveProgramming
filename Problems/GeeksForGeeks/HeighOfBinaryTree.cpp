//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
<<<<<<< HEAD
// Time complexity
=======
// Time complexity: O(n) n -> nodes
>>>>>>> 63ea76935ce094a57801ee067e9717a10a020c28

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
    struct Node{
      Node *left;
      Node *right;
      int data;
    };

    public:
      //Checks root
    int height(struct Node* node){
        if(node == nullptr) return 0;
        return height2(node, 0);
    }

    //Checks children
    int height2(Node* node, int h){
        if(node != nullptr) return max(height2(node -> left, h+1), height2(node -> right, h+1));
        return h;
    }
};
