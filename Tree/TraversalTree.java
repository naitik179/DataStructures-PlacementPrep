import java.util.*;
class Node 
{ 
	int key; 
	Node left, right; 

	public Node(int item) 
	{ 
		key = item; 
		left = right = null; 
	} 
} 

class TraversalTree 
{ 
	Node root; 

	TraversalTree() 
	{ 
		root = null; 
	} 

	void printPostorder(Node node) 
	{ 
		// left - right - root
		if (node == null) 
			return; 

		// first recur on left subtree 
		printPostorder(node.left); 

		// then recur on right subtree 
		printPostorder(node.right); 

		// now deal with the node 
		System.out.print(node.key + " "); 
	} 

	void printInorder(Node node) 
	{ 

		// left - root - right 
		if (node == null) 
			return; 

		/* first recur on left child */
		printInorder(node.left); 

		/* then print the data of node */
		System.out.print(node.key + " "); 

		/* now recur on right child */
		printInorder(node.right); 
	} 

	/* Given a binary tree, print its nodes in preorder*/
	void printPreorder(Node node) 
	{ 

		// root - left - right 

		if (node == null) 
			return; 

		/* first print data of node */
		System.out.print(node.key + " "); 

		/* then recur on left sutree */
		printPreorder(node.left); 

		/* now recur on right subtree */
		printPreorder(node.right); 
	} 

	// void printPostorder() {	 printPostorder(root); } 
	// void printInorder() {	 printInorder(root); } 
	// void printPreorder() {	 printPreorder(root); } 

	public static void main(String[] args) 
	{ 
		TraversalTree tree = new TraversalTree();
		tree.root = new Node(1); 
		tree.root.left = new Node(2); 
		tree.root.right = new Node(3); 
		tree.root.left.left = new Node(4); 
		tree.root.left.right = new Node(5); 

		System.out.println("Preorder traversal of binary tree is "); 
		tree.printPreorder(tree.root); 

		System.out.println("\nInorder traversal of binary tree is "); 
		tree.printInorder(tree.root); 

		System.out.println("\nPostorder traversal of binary tree is "); 
		tree.printPostorder(tree.root); 
	} 
} 
