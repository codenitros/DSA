// https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/


// TC - O(n^2)

// recursively update that subtree since an update to a node
// will break the children sum property for that sub-tree
void increment(node* node, int diff){
    if(node->left){
        node->left->data+=diff;
        increment(node->left, diff);
    }else{
        node->right->data+=diff;
        increment(node->right, diff);
    }
}



void convertTree(node* node){
    int left_val=0, right_val=0;

    if(!node || (!node->left && !node->right)){
        return;
    }else{

        convertTree(node->left);
        convertTree(node->right);

        if(node->left)left_val=node->left->data;
        if(node->right)right_val=node->right->data;

        int diff = left_val+right_val - node->data;

        if(diff > 0){ // parent value is less than sum of children
            node->data+=diff;
        }

        if(diff < 0){ // children value is less than parent
            increment(node, -diff);
        }
    }
}