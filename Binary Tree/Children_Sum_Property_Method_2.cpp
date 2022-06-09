// https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723


// TC - O(n)
// Taking advantage that tree nodes can be incremented to any value


void reorder(BinaryTreeNode<int> * root){
    if(!root || (!root->left && !root->right)return;
    
    // going top down

    int sumChild=0;
    if(root->left)sumChild+=root->left->val;
    if(root->right)sumChild+=root->right->val;
    if(root->val > sumChild){
        if(root->left)root->left->val = sumChild;
        if(root->right)root->right->val = sumChild;
    }

    reorder(root->left);
    reorder(root->right);

    // going bottom up

    // forfully add-up children and make parent equal to that sum
    int tot=0;
    if(root->left)tot+=root->left->val;
    if(root->right)tot+=root->right->val;
    if(root->left || root->right){
        root->val=tot;
    }
}






void changeTree(BinaryTreeNode<int> * root) {
    reorder(root);
}  