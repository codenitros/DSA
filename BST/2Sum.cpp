// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/


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
    bool search(TreeNode* root, int target){
        if(!root)return false;
        
        if(root->val == target)return true;
        if(root->val < target)search(root->right, target);
        else search(root->left, target);
        
        return false;
    }
    bool dfs(TreeNode* root, int k){
        if(!root)return false;
        return search(root, k-root->val) ||  dfs(root->left, k) || dfs(root->right, k);
        
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};