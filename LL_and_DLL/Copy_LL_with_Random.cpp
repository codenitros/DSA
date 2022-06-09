// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Not optimal
    Node* copyRandomList(Node* head) {
        // O(N) + O(N) for doing two passes
        // O(N) SC - hash map
        
        // map random of original for referring later
        if(!head)return ;
        unordered_map<Node*, Node*> randomMap;
        Node* temp = head;
        while(temp!=NULL){
            randomMap[temp] = new Node(temp->val);
            temp=temp->next;
        }
        
        // construct copy using next
        temp = head;
        Node* copyHead = new Node(0);
        Node* res = copyHead; 
        while(temp!=NULL){
            copyHead->next = randomMap[temp];
            copyHead->next->random = randomMap[temp->random];
            temp=temp->next;
            copyHead=copyHead->next;
        }
        
        return res->next;
    }
    
    
    // Optimal
    Node* copyRandomList(Node* head) {
        // Step 1:  point the next of each original to its deep copy
        Node* temp = head;
        while(temp!=NULL){
            Node* newnode = new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
        }
        
        // step-2: mark the random of deeps copy 
        Node* iter=head;
        while(iter!=NULL){
            if(iter->random!=NULL){
                iter->next->random = iter->random->next;
            }
            iter=iter->next->next;
        }
        
        // step-3: connect all deep copy nodes together
        Node* dummy = new Node(0);
        iter = head;
        temp = dummy;
        Node* fast;
        while(iter != NULL) {
            fast = iter->next->next;
            temp->next = iter->next;
            iter->next = fast;
            temp = temp->next;
            iter = fast;
        }
        return dummy->next;
    }
};