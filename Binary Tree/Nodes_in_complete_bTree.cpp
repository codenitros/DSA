// https://leetcode.com/problems/count-complete-tree-nodes/


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


 // if left height of the node and right height from a node is same
 // we can directly get total nodes in subtree by using formula
 // 2^height-1 -- applicable for complete binary tree
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        
        if(lh==rh)return pow(2,lh)-1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int findHeightLeft(TreeNode* root){
        if(!root)return 0;
        
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }
    
    int findHeightRight(TreeNode* root){
        if(!root)return 0;
        
        int height=0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }
};