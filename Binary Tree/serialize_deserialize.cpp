// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string getLevelOrder(TreeNode* root){
        
        string ret="";
        queue<TreeNode*> mQ;
        mQ.push(root);
        
        while(!mQ.empty()){
            int sz=mQ.size();
            
            while(sz--){
                TreeNode* temp=mQ.front();
                mQ.pop();
                
                if(temp->val==INT_MIN){
                    ret+="#,";
                    continue;
                }
                else{
                    ret+=to_string(temp->val);
                    ret+=',';
                } 
                
                if(temp->left)mQ.push(temp->left);
                else mQ.push(new TreeNode(INT_MIN));
                
                if(temp->right)mQ.push(temp->right);
                else mQ.push(new TreeNode(INT_MIN));
            }
        }
        return ret;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // convert to level order     
        if(!root)return "";
        return getLevelOrder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // build using level order
        //cout<<data;
        if(data.length()==0)return NULL;
        stringstream s(data); // will convert string items to objects
        string str;
        getline(s, str, ','); // str will contain next number
        
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> mQ;
        mQ.push(root);
        
        while(!mQ.empty()){
            TreeNode* cur = mQ.front();
            mQ.pop();
            
            getline(s, str, ',');
            if(str=="#"){
                cur->left=NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                cur->left=leftNode;
                mQ.push(leftNode);
            }
            
            getline(s, str, ',');
            if(str=="#"){
                cur->right=NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                cur->right=rightNode;
                mQ.push(rightNode);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));