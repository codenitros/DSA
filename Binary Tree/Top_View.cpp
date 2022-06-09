// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL)return ans;
        
        // use map since we need sorted vertical
        // map<vertical, value>
        map<int, int> myMap;
        
        // queue<Node*, vertical>
        queue<pair<Node*, int>> myQ;
        
        myQ.push({root, 0});
        
        while(!myQ.empty()){
            auto temp = myQ.front();
            myQ.pop();
            
            Node* node = temp.first;
            int vertical = temp.second;
            
            // only insert  if we have not inserted any for this level
            // this the main difference for bottom view
            if(myMap.find(vertical)==myMap.end())myMap[vertical] = node->data;
            
            if(node->left!=NULL){
                myQ.push({node->left, vertical-1});
            }
            if(node->right!=NULL){
                myQ.push({node->right, vertical+1});
            }
        }
        
        // get values from our map whose key is already sorted from
        // left to right vertical
        for(auto val:myMap){
            ans.push_back(val.second);
        }
        return ans;
    }
};
