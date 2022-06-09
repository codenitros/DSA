// https://leetcode.com/problems/add-two-numbers/


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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum,carry=0;
        ListNode* result= NULL;
        ListNode *prev,*temp=NULL;
        
        while(l1!=NULL || l2!=NULL)
        {
            /*
            1->2->3->4->NULL
            3->4->NULL
            
            one LL can be smaller so below logic should be used 
            */
            sum = carry + (l1 ? l1->val:0) + (l2 ? l2->val:0);
            
            carry = sum>=10 ? 1:0;
            
            sum=sum%10;
            
            temp = new ListNode(sum);
            
            if(result==NULL)
            {
                result = temp;
            }
            else
            {
                prev->next=temp;
            }
            
            prev=temp;
            
            if(l1){
                l1=l1->next;
            }
            if(l2)
            {
                l2=l2->next;
            }
        }
        if(carry > 0)
        {
            temp->next=new ListNode(carry);
        }
        return result;
    }
};