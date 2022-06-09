class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return {};
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            
            if(cur->right)s.push(cur->right);
            if(cur->left)s.push(cur->left);
            
        }
        return ans;
    }
};