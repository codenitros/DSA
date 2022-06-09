//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void bfsToMapParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mpp, TreeNode* start)     
    {
        queue<TreeNode*> q; 
        q.push(root); 
        TreeNode* res; 
        while(!q.empty()) {
            TreeNode* node = q.front(); 
            q.pop(); 

            if(node == start) res = node; 

            if(node->left) {
                mpp[node->left] = node; 
                q.push(node->left); 
            }
            if(node->right) {
                mpp[node->right] = node;
                q.push(node->right); 
            }
        }; 
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // we need to move up also in the BT
        // so we need parent pointers - build it
        unordered_map<TreeNode*,TreeNode*> parentMap;
        bfsToMapParents(root, parentMap, target);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> mQ;
        mQ.push(target);
        visited[target]=true;
        
        int cur_dist=0;
        while(!mQ.empty()){
            int size = mQ.size();
            if(cur_dist++ == k)break;
            
            while(size--){
                TreeNode* cur = mQ.front();
                mQ.pop();
            
                if(cur->left && !visited[cur->left]) {
                    mQ.push(cur->left);
                    visited[cur->left]=true;
                }
                if(cur->right && !visited[cur->right]) {
                    mQ.push(cur->right);
                    visited[cur->right]=true;
                }
                if(parentMap[cur] && !visited[parentMap[cur]]){
                    mQ.push(parentMap[cur]);
                    visited[parentMap[cur]]=true;
                }
            }
        }
        vector<int> ans;
        while(!mQ.empty()){
            TreeNode* node = mQ.front();
            mQ.pop();
            ans.push_back(node->val);
        }
        
        return ans;
        
    }
};