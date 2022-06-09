// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int myFunc(TreeNode *node, int &dia)
    {
        if(node==NULL)return 0;
        int ld = myFunc(node->left,dia);
        int rd = myFunc(node->right,dia);
        dia=max(dia,ld+rd);
        return 1+max(ld,rd);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        // return max(dia, left+right);
        int dia=0;
        myFunc(root,dia);
        return dia;
    }
};