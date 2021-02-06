#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
};


class Solution {
public:
    
    
    void print(Node* head){
          Node *temp = head;
        while(temp){
            if(!temp -> prev) cout << "Before node " << -1 << " ";
            else cout << "Before node " << temp -> prev -> val << " ";
            
            cout << "In node: "<< temp -> val << " ";
            
            if(!temp -> next) cout << "After node " << -1 << " ";
            else cout << "After node " << temp -> next -> val << " ";
            
            if(!temp -> child) cout << "Child node " << -1 << " ";
            else cout << "Child node " << temp -> child -> val << " ";
            
            cout << "\n";
            temp = temp -> next;
            if(!temp) cout << "not temp";
        }
        cout << "\n";
    }
    
    
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        aux(head);
        return head;
    }
    
     Node *aux(Node* head){
        Node *now = head, *next = now -> next, *child_end, *end, *temp;
        
        while(next || now -> child){
            if (now && now -> child){
                now -> next = now -> child;
                now -> child -> prev = now;
                
                child_end = aux(now -> child);
                cout << "returning: " << child_end -> val << endl;
                now -> child = nullptr;
                
                if(next) next -> prev = child_end;
                child_end -> next = next;
            }
            
            if(next) now = next;
            if(next) next = next -> next;
        }
        
        while(now -> next) now  = now -> next;
        
        return now;
    }
};

