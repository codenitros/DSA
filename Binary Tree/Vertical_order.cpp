//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          // map of vertical which maps to map of level and list of items in that vertical
          // using multiset to keep node values at same level and vertical sorted
          // dont use unordered_map since we need sorted vertical order eg -2 -1 0 1 2 (left to right)
          map<int, map<int, multiset<int>>> mMap;
        
          // queue of TreeNode, (vertcal, level)
          queue<pair<TreeNode*, pair<int, int>>> mQ;
          mQ.push({root,{0,0}}); 
          
          //initial vertical and level
          while (!mQ.empty()) {
            auto p = mQ.front();
            mQ.pop();
            TreeNode * temp = p.first;

            int vertical = p.second.first, level = p.second.second;
            mMap[vertical][level].insert(temp -> val); //inserting to multiset
            
            // when we got left vertical will reduce and increase when we go right,
            // level will always increase
            if (temp -> left) {
              mQ.push({temp -> left,{vertical - 1, level + 1}});
            }
            if (temp -> right) {
              mQ.push({temp -> right,{vertical + 1, level + 1}});
            }
          }
        
          // 
          vector<vector<int>> ans;
          for (auto p: mMap) {
            vector<int> col;
            // q is our second map,  level to multiset map for each vertical
            for (auto q: p.second) {
              col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
          }
          return ans;
    }
};