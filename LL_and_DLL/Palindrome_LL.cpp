// https://leetcode.com/problems/palindrome-linked-list/


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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;
        
        stack<int> S;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr && fastptr->next)
        {
            S.push(slowptr->val);
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
        }
        
        // if fastptr==NULL then its even length else its odd length
        // for odd length we need to move one position right
        if(fastptr!=NULL)slowptr=slowptr->next;
        
        while(slowptr)
        {
            if(slowptr->val != S.top())
            {
                return false;
            }
            S.pop();
            slowptr = slowptr->next;
        }
        
        return true;
    }
};