#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


// return true/false denoting whether the tree is Symmetric or not

bool aux(Node *left, Node *right);

bool isSymmetric(struct Node* root)
{
	if(!root) return true;
	return aux(root -> left, root -> right);
	
}

bool aux(Node *left, Node *right){
    if(left && right){
        if(left -> data == right -> data) return (aux(left -> left, right -> right) && aux(left -> right, right -> left)); 
        else return false;
    }
    else if(!left && right || left && !right){
        return false;
    }
    else return true;
}