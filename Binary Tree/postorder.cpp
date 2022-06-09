//https://leetcode.com/problems/binary-tree-postorder-traversal/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private ArrayList<Integer> ans = new ArrayList<Integer>();
    
    public void dfs(TreeNode root){
        if(root==null)return;
        
        dfs(root.left);
        dfs(root.right);
        ans.add(root.val);
    }
    
    public List<Integer> postorderTraversal(TreeNode root) {
        dfs(root);
        return ans;
    }
}