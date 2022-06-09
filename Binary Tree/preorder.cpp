//https://leetcode.com/problems/binary-tree-preorder-traversal/


class Solution {
    private ArrayList<Integer> ans = new ArrayList<Integer>();
    
    public void dfs(TreeNode root){
        if(root==null)return;
        
        ans.add(root.val);
        dfs(root.left);
        dfs(root.right);
        
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        dfs(root);
        return ans;
    }
}