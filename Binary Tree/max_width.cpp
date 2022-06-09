// https://leetcode.com/problems/maximum-width-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getMaxWidth(TreeNode* root, int &maxWidth){
        // modified level order traversal
        if(!root)return;
        
        // queue where each node keeps track of node and it number 
        
        /* tree numbering will look like 
                                       0
                                  0          1
                               0     1    2     3
           leftMost-->      0   1 2   3 4   5 6   7   <--- rightMost
           
        */
        queue<pair<TreeNode*,long long int>> myQ;
        myQ.push({root,0});
        
        while(!myQ.empty()){
            int s = myQ.size();
            
            // get the minimum id of that level (this is for overcoming integer overflow)
            int cur_min = myQ.front().second;
            int leftMost, rightMost;
            
            for(int i=0;i<s;i++){
                // hack to overcome overflow
                long long int cur_id = myQ.front().second - cur_min;
                TreeNode* temp = myQ.front().first;
                myQ.pop();
                
                if(i==0)leftMost = cur_id;
                if(i==s-1)rightMost = cur_id;
                
                if(temp->left)myQ.push({temp->left, 2 * cur_id + 1});
                if(temp->right)myQ.push({temp->right, 2 * cur_id + 2});
            }
            maxWidth = max(maxWidth, rightMost - leftMost + 1);
        }
    }
    
    
    
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth=0;
        getMaxWidth(root, maxWidth);
        return maxWidth;
    }
};