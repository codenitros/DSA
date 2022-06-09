//https://leetcode.com/problems/binary-tree-right-side-view/

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
    void getRightView(TreeNode* root, int level, vector<int> &res){
        if(!root) return;
        
        // Use reverse pre-order travresal (Node --> right -->left)
        
        // if our current level is equal to our data structure size then 
        // its the first node of that level so push it
        if(level == res.size()){
            res.push_back(root->val);
        }
        getRightView(root->right, level+1, res);
        getRightView(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        getRightView(root, 0, res);
        return res;
    }
};