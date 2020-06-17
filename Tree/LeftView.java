class Node
{
	int key;
	Node left = null, right = null;

	Node(int key) {
		this.key = key;
	}
}

class LeftView
{
	// Recursive function to print left view of given binary tree
	public static int lv(Node root, int level, int lastLevel)
	{
		// base case: empty tree
		if (root == null) {
			return lastLevel;
		}

		// if current node is first node of current level
		if (lastLevel < level)
		{
			// print the node's data
			System.out.print(root.key + " ");

			// update last level to current level
			lastLevel = level;
		}

		// recur for left and right subtree by increasing level by 1
		lastLevel = lv(root.left, level + 1, lastLevel);
		lastLevel = lv(root.right, level + 1, lastLevel);

		return lastLevel;
	}

	public static void leftView(Node root) {
		leftView(root, 1, 0);
	}

	public static void main(String[] args)
	{
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.right = new Node(4);
		root.right.left = new Node(5);
		root.right.right = new Node(6);
		root.right.left.left = new Node(7);
		root.right.left.right = new Node(8);

		leftView(root);
	}
}