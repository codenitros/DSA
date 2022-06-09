// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    TreeNode* prev = NULL;
    void recursiveFlatten(TreeNode* root){
        if(!root)return;
        // reverse post order is needed 
        flatten(root->right);
        flatten(root->left);
        
        // do this for each node
        root->right = prev;
        root->left = NULL;
        prev = root; 
    }
    
    void iterativeFlatten(TreeNode* root){
        if(!root)return;
        stack<TreeNode*> mS;
        mS.push(root);
        
        // a stack of reverse post order
        while(!mS.empty()){
            TreeNode* cur = mS.top();
            mS.pop();
            
            if(cur->right)mS.push(cur->right);
            if(cur->left)mS.push(cur->left);
            
            if(!mS.empty())cur->right = mS.top();
            cur->left = NULL;
        }
    }
    
    void flatten(TreeNode* root) {
        //iterativeFlatten(root);
        recursiveFlatten(root);
    }
};