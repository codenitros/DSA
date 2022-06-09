// https://leetcode.com/problems/reorder-list

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
    void reorderList(ListNode* head) {
        // 1 -> 2 -> 5 -> 4 -> 3
        // 1 -> 5 -> 2 -> 4 -> 3
        
        // Get the Mid
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // slow is mid
        // reverse the second part
        ListNode* prev = NULL;
        ListNode* cur=slow->next;
        while(cur){
            ListNode* nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        
        // mark last of first part as NULL
        slow->next=NULL;
        
        
        // Merge both parts one by one
        ListNode* head1 = head;
        ListNode* head2 = prev;
        
        while(head2){
            ListNode* temp = head1->next;
            head1->next=head2;
            head1=head1->next;
            head2=temp;
        }
        
    }
};