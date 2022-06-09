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
    vector<int> sorted;
public:

    //Approach - 1
    int kthSmallest(TreeNode* root, int k) {
        // TC - O(n)
        // SC - O(1)
        
        // Morris Traversal
        stack<TreeNode*> stk;
        TreeNode* node = root;
        int cnt=0;
        
        while(true){
            if(node!=NULL){
                stk.push(node);
                node=node->left;
            }else{
                if(stk.empty()){
                    break;
                }
                node = stk.top();
                stk.pop();
                cnt++;
                if(cnt==k)return node->val;
                node=node->right;
            }
        }
        return -1;
    }
    
    
    //Approach - 2
    //TC - O(n)
    //SC - stack space O(n)
    void inorder(TreeNode* root, int& count,int k, int& ans){
        if(!root)return;

        inorder(root->left, count, k, ans);
        count++;
        if(count==k)ans=root->val;
        inorder(root->right, count, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0, ans;
        inorder(root, count, k, ans);
        return ans;
    }
    
    
    
    //Approach - 3
    // TC- O(n), SC-O(n)
    void inorder(TreeNode* root){
        if(!root)return;
        
        inorder(root->left);
        sorted.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return sorted[k-1];
    }
    
};