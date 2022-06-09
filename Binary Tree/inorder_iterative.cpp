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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        
        // explore all left nodes
        while(root){
            stk.push(root);
            root=root->left;
        }
        
        while(!stk.empty()){
            // collect node value
            root = stk.top();
            stk.pop();
            ans.push_back(root->val);
            
            // explore all left nodes of current right node
            root=root->right;
            while(root){
                stk.push(root);
                root=root->left;
            }
        }
        return ans;   
    }
};