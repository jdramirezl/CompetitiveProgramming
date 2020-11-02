// https://leetcode.com/problems/insertion-sort-list/submissions/
// Time complexity: O(n^2)

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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return head;
        return recursive(head);
    }
    
    ListNode* recursive(ListNode* head){
        ListNode *now = head, *temp, *last = new ListNode(), *temp2, *last2;
        
        bool out = true;
        while(now != nullptr && now -> next != nullptr){
            
            if(now -> val > now -> next -> val){
                if(head == now){ 
                    head = now -> next;
                    now -> next = head -> next;
                    head -> next = now;
                }
                else{
                    temp = now -> next; //menor
                    now -> next = temp -> next;
                    temp2 = head;
                    
                    
                    while(temp -> val > temp2 -> val){
                        last2 = temp2;
                        temp2 = temp2 -> next;
                    }
                    
                    if(temp2 == head){
                        head = temp;
                        head -> next = temp2;
                    }
                    else{
                        last2 -> next = temp;
                        temp -> next = temp2;
                    } 
                }
            }
            else{
                last = now;
                now = now -> next;
            }
        }
        return head;
    }
};

int main(){

}