// https://leetcode.com/problems/rotate-list/

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
    int getLLLength(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        
        int length = getLLLength(head);
        k=k%length;
        if(k==0)return head;


        int move = length - k - 1;
        ListNode* temp = head;
        while(move-- && temp){
            temp=temp->next;
        }
        
        ListNode* nex = temp->next;
        ListNode* newHead = nex;
        temp->next=NULL;
        
        while(nex->next){
            nex=nex->next;
        }
        nex->next=head;
        return newHead;
    }
};