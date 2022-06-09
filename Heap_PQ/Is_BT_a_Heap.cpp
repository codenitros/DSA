// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    
    bool isComplete(struct Node* root, int nodeCount, int idx){
        if(!root)return true;
        
        // index assigned cannot be greater than total nodes if it is a complete binary tree
        if(idx > nodeCount)return false;
        
        return isComplete(root->left, nodeCount, 2*idx+1) && isComplete(root->right, nodeCount, 2*idx+2);
    }
    
    bool isParentGreater(struct Node* root){
        if(!root) return true;
        if(!root->left && !root->right)return true;
        
        if(root->right==NULL){
            return (root->left->data < root->data);
        }else{
            if(root->right->data < root->data && root->left->data < root->data){
                return (isParentGreater(root->left) && isParentGreater(root->right));
            }else{
                return false;
            }
        }
        
    }
    
    int getNodeCounts(struct Node* node){
        if(!node)return 0;
        return (1 + getNodeCounts(node->left)  + getNodeCounts(node->right));
                
    }
  
    bool isHeap(struct Node* root) {
        if(!root)return true;
        
        int NodeCount = getNodeCounts(root);
        int idx=0;
        
        return (isComplete(root, NodeCount, idx) && isParentGreater(root));
    }
};
