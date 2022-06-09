// https://leetcode.com/problems/binary-tree-maximum-path-sum/


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
    int getMaxSum(TreeNode* root, int& maxSum){
        if(!root)return 0;
        
        // since negative numbers are allowed as node data 
        // max check with 0 is needed
        int leftMax = max(0, getMaxSum(root->left, maxSum));
        int rightMax = max(0, getMaxSum(root->right, maxSum));
        
        // our core logic here
        maxSum = max(maxSum, leftMax +  rightMax + root->val);
        
        //this return is for recursion 
        return max(leftMax, rightMax) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        getMaxSum(root, maxSum);
        return maxSum;
        
    }
};