// https://leetcode.com/problems/linked-list-cycle/


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
    bool hasCycle(ListNode *head) {
        ListNode* slowptr=head;
        ListNode* fastptr=head;
        
        while(fastptr && fastptr->next){
            fastptr=fastptr->next->next;
            slowptr= slowptr->next;
            if(slowptr==fastptr)return 1;
        }
        return 0;
    }
};