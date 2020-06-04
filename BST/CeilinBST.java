 class Node { 

	int data; 
	Node left, right; 

	Node(int d) 
	{ 
		data = d; 
		left = right = null; 
	} 
} 

class CeilinBST { 

	Node root; 

	// Function to find ceil of a given input in BST. 
	// If input is more than the max key in BST, 
	// return -1 
	int Ceil(Node node, int input) 
	{ 

		// Base case 
		if (node == null) { 
			return -1; 
		} 

		// We found equal key 
		if (node.data == input) { 
			return node.data; 
		} 

		// If root's key is smaller, 
		// ceil must be in right subtree 
		if (node.data < input) { 
			return Ceil(node.right, input); 
		} 

		// Else, either left subtree or root 
		// has the ceil value 
		int ceil = Ceil(node.left, input); 
		
		return (ceil >= input) ? ceil : node.data; 
	} 

	public static void main(String[] args) 
	{ 
		CeilinBST tree = new CeilinBST(); 
		tree.root = new Node(8); 
		tree.root.left = new Node(4); 
		tree.root.right = new Node(12); 
		tree.root.left.left = new Node(2); 
		tree.root.left.right = new Node(6); 
		tree.root.right.left = new Node(10); 
		tree.root.right.right = new Node(14); 
		for (int i = 0; i < 16; i++) { 
			
			System.out.println(i + " " + tree.Ceil(tree.root, i)); 
		} 
	} 
} 

