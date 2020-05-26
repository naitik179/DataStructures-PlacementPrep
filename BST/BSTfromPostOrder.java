// Class to store a Binary Tree node
class Node
{
	int key;
	Node left, right;

	Node(int key) {
		this.key = key;
	}
}

class BSTfromPostOrder
{
	// Recursive function to perform inorder traversal of a binary tree
	public static void inorder(Node root)
	{
		if (root == null) {
			return;
		}

		inorder(root.left);
		System.out.print(root.key + " ");
		inorder(root.right);
	}

	// Recursive function to build a binary search tree from
	// its postorder sequence
	public static Node constructBST(int[] postorder, int start, int end)
	{
		// base case
		if (start > end) {
			return null;
		}

		// Construct the root node of the subtree formed by keys of the
		// postorder sequence in range [start, end]
		Node node = new Node(postorder[end]);

		// search the index of last element in current range of postorder
		// sequence which is smaller than the value of root node
		int i;
		for (i = end; i >=start; i--) {
			if (postorder[i] < node.key) {
				break;
			}
		}

		// Build right subtree before left subtree since the values are
		// being read from the end of the postorder sequence

		// recursively construct the right subtree
		node.right = constructBST(postorder, i + 1, end - 1);

		// recursively construct the left subtree
		node.left = constructBST(postorder, start, i);

		// return current node
		return node;
	}

	public static void main(String[] args)
	{
		/* Construct below BST
	              15
	            /    \
	           /      \
	          10       20
	         /  \     /  \
	        /     \  /    \
	       8     12 16     25
		*/

		int[] postorder = { 8, 12, 10, 16, 25, 20, 15 };

		// construct the BST
		Node root = constructBST(postorder, 0, postorder.length - 1);

		// print the BST
		System.out.print("Inorder Traversal of BST is : ");

		// inorder on the BST always returns a sorted sequence
		inorder(root);
	}
}