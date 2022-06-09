// https://leetcode.com/problems/odd-even-linked-list/


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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = even;
        
        while(odd->next!=NULL && even->next!=NULL && odd!=NULL && even!=NULL){
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }
        
        if(even!=NULL)even->next= NULL;
        odd->next = temp;
        return head;
    }
};