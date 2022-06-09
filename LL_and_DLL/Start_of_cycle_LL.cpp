// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }
        if(slow!=fast)return NULL; // no cycle
        
        
        ListNode* start = head;
        while(start!=slow){
            start=start->next;
            slow=slow->next;
        }
        return start;
    }
};