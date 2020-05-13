
class Node { 
	int data; 
	Node left, right; 
	Node(int d) 
	{ 
		data = d; 
		left = right = null; 
	} 
} 

class AVLTreeorNot { 
    Node root; 
    
	boolean isBalanced(Node node) 
	{ 
		int lh; /* for height of left subtree */

		int rh; /* for height of right subtree */

		if (node == null) 
			return true; 

		lh = height(node.left); 
		rh = height(node.right); 

		if (Math.abs(lh - rh) <= 1
			&& isBalanced(node.left) 
			&& isBalanced(node.right)) 
			return true; 

		return false; 
	} 

	int height(Node node) 
	{ 
		if (node == null) 
			return 0; 

		return 1 + Math.max(height(node.left), height(node.right)); 
	} 

	public static void main(String args[]) 
	{ 
		AVLTreeorNot tree = new AVLTreeorNot(); 
		tree.root = new Node(3); 
		tree.root.left = new Node(9); 
		tree.root.right = new Node(20); 
		tree.root.right.left = new Node(4); 
		tree.root.right.right = new Node(5);  

		if (tree.isBalanced(tree.root)) 
			System.out.println("Tree is balanced"); 
		else
			System.out.println("Tree is not balanced"); 
	} 
} 
 
/*

    BALANCED
            3
        9       20
             15    7

 ---------------------------------

    NOT BALANCED
            3
        9       20
             15     7
                  1
                3

*/

