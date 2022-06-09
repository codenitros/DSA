/* This is the Node class definition

class Node {
	public Node left;
    public Node right;
    int data;

    Node(int data) {
        this.data = data;
    }
}
*/

class Solution {
	void invert(Node root){
		if(root==null)return;
		Node temp = root.left;
		root.left = root.right;
		root.right = temp;
		
		invert(root.left);
		invert(root.right);
		
	}
	void invertTree(Node root) {
    	invert(root);
	}
}