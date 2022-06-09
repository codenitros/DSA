// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root)return {};
        vector<vector<int>> res;
        queue<TreeNode*> mQ;
        mQ.push(root);
        while(!mQ.empty()){
            int size = mQ.size();
            vector<int> temp;
            
            while(size--){
                TreeNode* cur = mQ.front();
                mQ.pop();
                temp.push_back(cur->val);
                
                if(cur->left)mQ.push(cur->left);
                if(cur->right)mQ.push(cur->right);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};