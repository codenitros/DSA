// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& inorder, int inStart, int inEnd,
                    map<int, int>& inMap)
    {
        if(preStart > preEnd || inStart > inEnd)return NULL;

        TreeNode* cur = new TreeNode(preorder[preStart]);
        int inPos = inMap[preorder[preStart]];
        int numsLeft = inPos - inStart;

        cur->left= build(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inPos-1, inMap);
        cur->right=build(preorder, preStart+numsLeft+1, preEnd, inorder, inPos+1, inEnd, inMap);
        return cur;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // map inorder for faster access
        map<int, int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        
        TreeNode* root =  build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};
