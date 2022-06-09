// 


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
    TreeNode* bstHelper(vector<int>& preorder, int rootIdx, int right){
        if(rootIdx >= right)return NULL;
        TreeNode* node = new TreeNode(preorder[rootIdx]);

        int i=rootIdx+1;
        while(i<preorder.size() && preorder[i] < preorder[rootIdx]){
            i++;
        }

        node->left=bstHelper(preorder, rootIdx+1, i);
        node->right=bstHelper(preorder, i+1, right);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstHelper(preorder, 0, preorder.size());
    }
};