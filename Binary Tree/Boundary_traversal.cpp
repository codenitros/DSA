// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/

// boundary traversal of binary tree

#define pb push_back


class Solution {
    bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL)return true;
        return false;
    }
public:
    void appendLeftBoundary(Node* root, vector<int> &ans){
        Node* cur = root->left;
        while(cur){
            if(!isLeaf(cur))ans.pb(cur->data);
            if(cur->left)cur = cur->left;
            else cur = cur->right;
        }
    }
    
    void appendLeaf(Node* root, vector<int> &ans){
        if(isLeaf(root)){
            ans.pb(root->data);
            return;
        }
        if(root->left)appendLeaf(root->left, ans);
        if(root->right)appendLeaf(root->right, ans);
    }
    
    void appendReverseRightBoundary(Node* root, vector<int> &ans){
        Node* cur = root->right;
        vector<int> temp;
        while(cur){
            if(!isLeaf(cur))temp.pb(cur->data);
            if(cur->right)cur = cur->right;
            else cur = cur->left;
        }
        for(int i=temp.size()-1;i>=0;--i){
            ans.pb(temp[i]);
        }
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> res;
        if(!root)return res;
        if(!isLeaf(root))res.pb(root->data);
        
        appendLeftBoundary(root, res);
        appendLeaf(root, res);
        appendReverseRightBoundary(root, res);
        
        return res;
        
    }
};