// https://leetcode.com/problems/delete-node-in-a-bst/

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
    
    TreeNode* findLastRight(TreeNode* node){
        if(node->right==NULL)return node;
        
        return findLastRight(node->right);
    }
    
    TreeNode* helper(TreeNode* root){
        if(!root->left)return root->right;
        else if(!root->right) return root->left;
        
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        
        TreeNode* lastRight = findLastRight(leftChild);
        lastRight->right = rightChild;
        return leftChild;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        
        
        if(root->val==key){
            return helper(root);
        }
        
        
        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){ // key is in the left
                if(root->left && root->left->val==key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root=root->left;
                }
            }else{
                if(root->right && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
};