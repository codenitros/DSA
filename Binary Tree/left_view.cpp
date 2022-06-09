// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1


void getLeftView(Node* root, int level, vector<int> &res){
    if(!root)return;
    
    
    if(level == res.size()){
        res.push_back(root->data);
    }
    
    getLeftView(root->left, level+1, res);
    getLeftView(root->right, level+1, res);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   getLeftView(root, 0, res);
   return res;
}
