//https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_A=0,len_B=0,len;
        ListNode *temp = headA,*temp2;
        
        if(headA==NULL || headB==NULL)return NULL;

        // Obtain length of both LL
        while(temp!=NULL){
            len_A++;
            temp=temp->next;
        }
        temp = headB;
        
        while(temp!=NULL){
            len_B++;
            temp=temp->next;
        }
        len = abs(len_A-len_B);
        
        temp=headA;
        temp2 = headB;
        

        // Move the longer LL to abs(a-b)
        if(len_A > len_B){
            for(int i = 0;i < len;i++) {
                temp = temp->next;}
        }else{
            for(int i = 0;i < len;i++) {
                temp2 = temp2->next;}
        }

        // move syncronously until there is intersection
        while(temp!=temp2)
        {
            temp=temp->next;
            temp2=temp2->next;
        }
        return temp;
        
    }
};