// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* build(vector<int>& postorder, 
                    int postStart, 
                    int postEnd,
                    vector<int>& inorder, 
                    int inStart, 
                    int inEnd,
                    map<int,int>& inMap){
        
        // base case (until there is postorder to calculate or inroder)
        if(postStart > postEnd || inStart > inEnd)return NULL;
        
        // make root from our postorder last element 
        TreeNode* node = new TreeNode(postorder[postEnd]);
        
        // find where it lies in inorder using our map
        int inRoot = inMap[node->val];
        
        // find number of elements to the left of the found number in inorder
        int numsLeft = inRoot - inStart;
        
        // created node's left and right will be built using recursion
        node->left  = build(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, inMap);
        node->right = build(postorder, postStart+numsLeft+1, postEnd-1, inorder, inRoot+1, inEnd, inMap);
        return node;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        
        TreeNode* root =  build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};