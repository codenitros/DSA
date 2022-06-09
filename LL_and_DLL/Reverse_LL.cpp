// https://leetcode.com/problems/reverse-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* iterativeApproach(ListNode* head){
        ListNode* prev = NULL;
        ListNode* nex;
        
        while(head!=NULL){
            nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
    
    ListNode* recursiveApproach(ListNode* head){
        if(!head || !head->next)return head;
        
        ListNode* newHead = recursiveApproach(head->next);
        head->next->next = head;
        head->next=NULL;
            
        return newHead;
    }
    
    
    ListNode* reverseList(ListNode* head) {
        return iterativeApproach(head);
        //return recursiveApproach(head);
    }
};