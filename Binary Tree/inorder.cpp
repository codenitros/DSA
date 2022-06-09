// https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
    private ArrayList<Integer> ans = new ArrayList<Integer>();
    
    public void dfs(TreeNode root){
        if(root==null)return;
        
        dfs(root.left);
        ans.add(root.val);
        dfs(root.right);
        
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        dfs(root);
        return ans;
    }
}