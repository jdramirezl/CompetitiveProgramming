#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1;
        stack<int> num2;
        stack<int> nums;
        
        while(l1){
            num1.push(l1 -> val);
            l1 = l1 -> next;
        }
        
        while(l2){
            num2.push(l2 -> val);
            l2 = l2 -> next;
        }
        
        int big = max(num2.size(), num1.size()), temp, residue = 0;
        for(int i = 0; i<big; ++i){
            temp = 0;
            temp += residue;
            if(!num1.empty()){
                temp += num1.top();
                num1.pop();
            }
            
            if(!num2.empty()){
                temp += num2.top();
                num2.pop();
            }
            
            if(temp >= 10){
                residue = temp/10;
                temp %= 10;
            }
            else residue = 0;
            
            nums.push(temp);
        }
        
        if(residue != 0) nums.push(residue);
        
        ListNode *head = new ListNode();
        ListNode *node = head;
        
        while(nums.size() > 1){
            node -> val = nums.top();
            nums.pop();
            node -> next = new ListNode();
            node = node -> next;
        }
        
        node -> val = nums.top();
        
        return head;
    }
};