//https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverse(ListNode* head, int size, int k)
    {
        if(size<k)return head;
        
        // number of segments ofsize k we have to reverse
        int n=size/k;
        
        ListNode* prev,*cur=head,*next_node,*start_prev,*start_cur;
        
        // for each segment
        for(int i=0;i<n;i++)
        {
            prev=NULL;
            start_cur=cur;
            for(int j=0;j<k;j++)
            {
                next_node=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next_node;
            }
        
            
            //point to latest head
            if(i==0)
            {
                head=prev;
            }
            
            /* 
            *  for linking segments, prev segment start will be its start cur after reverse 
            *  and that will link with current segment prev 
            *  which will be our first node of current segment after reverse.
            */
            if(i>0)
            {
                start_prev->next=prev;
            }
            start_prev=start_cur;
        }
        
        // for linking to rest of the elements at the end that do not form segment
        if(start_cur)
        {
            start_cur->next=cur;
        }
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)return head;
        
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            size++;
        }
        
        return reverse(head,size,k);
    }
};