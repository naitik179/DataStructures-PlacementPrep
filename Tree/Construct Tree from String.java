class GFG 
{ 
static class Node 
{ 
	int data; 
	Node left, right; 
}; 
static String str; 

/* Helper function that allocates a new node */
static Node newNode(int data) 
{ 
	Node node = new Node(); 
	node.data = data; 
	node.left = node.right = null; 
	return (node); 
} 

// Function to construct string from binary tree 
static void treeToString(Node root) 
{ 
	// bases case 
	if (root == null) 
		return; 

	// push the root data as character 
	str += (Character.valueOf((char) 
		(root.data + '0'))); 

	// if leaf node, then return 
	if (root.left == null && root.right == null) 
		return; 

	// for left subtree 
	str += ('('); 
	treeToString(root.left); 
	str += (')'); 

	// only if right child is present to 
	// avoid extra parenthesis 
	if (root.right != null) 
	{ 
		str += ('('); 
		treeToString(root.right); 
		str += (')'); 
	} 
} 

// Driver Code 
public static void main(String[] args) 
{ 
	
	/* Let us construct below tree 
			1 
			/ \ 
			2 3 
			/ \ \ 
			4 5 6 */
	Node root = newNode(1); 
	root.left = newNode(2); 
	root.right = newNode(3); 
	root.left.left = newNode(4); 
	root.left.right = newNode(5); 
	root.right.right = newNode(6); 
	str = ""; 
	treeToString(root); 
	System.out.println(str); 
} 
} 

