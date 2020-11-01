//https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// Time complexity: O(n) n -> Nodes

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
  Node *left;
  Node *right;
  int data;
};

bool isIdentical(Node *r1, Node *r2){
  if((r1 == nullptr && r2 != nullptr) || (r1 != nullptr && r2 == nullptr)) return false;
  if(r1 == nullptr && r2 == nullptr) return true;
  return ((r1 -> data == r2 -> data) && (isIdentical(r1 -> left, r2 -> left)) && (isIdentical(r1 -> right, r2 -> right)));
}
