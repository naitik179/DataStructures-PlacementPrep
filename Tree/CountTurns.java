/*

Case 2.
Given Binary Tree and two nodes 5 & 10 
                    1
                /      \
             2           3
            /  \       /   \
          4     5      6     7
        /                  /   \
      8                  9       10

Number of Turns needed to reach from 5 to 10 is 4.



*/


public class Turns_to_reach_another_node { 

	// making Count global such that it can get 
	// modified by different methods 
	static int Count; 

	// A Binary Tree Node 
	static class Node { 
		Node left, right; 
		int key; 

		// Constructor 
		Node(int key) { 
			this.key = key; 
			left = null; 
			right = null; 
		} 
	} 

	// Utility function to find the LCA of 
	// two given values n1 and n2. 
	static Node findLCA(Node root, int n1, int n2) { 
		// Base case 
		if (root == null) 
			return null; 

		// If either n1 or n2 matches with 
		// root's key, report the presence by 
		// returning root (Note that if a key 
		// is ancestor of other, then the 
		// ancestor key becomes LCA 
		if (root.key == n1 || root.key == n2) 
			return root; 

		// Look for keys in left and right subtrees 
		Node left_lca = findLCA(root.left, n1, n2); 
		Node right_lca = findLCA(root.right, n1, n2); 

		// If both of the above calls return 
		// Non-NULL, then one key is present 
		// in once subtree and other is present 
		// in other, So this node is the LCA 
		if (left_lca != null && right_lca != null) 
			return root; 

		// Otherwise check if left subtree or right 
		// subtree is LCA 
		return (left_lca != null) ? left_lca : right_lca; 
	} 

	// function count number of turn need to reach 
	// given node from it's LCA we have two way to 
	static boolean CountTurn(Node root, int key, boolean turn) { 
		if (root == null) 
			return false; 

		// if found the key value in tree 
		if (root.key == key) 
			return true; 

		// Case 1: 
		if (turn == true) { 
			if (CountTurn(root.left, key, turn)) 
				return true; 
			if (CountTurn(root.right, key, !turn)) { 
				Count += 1; 
				return true; 
			} 
		} else // Case 2: 
		{ 
			if (CountTurn(root.right, key, turn)) 
				return true; 
			if (CountTurn(root.left, key, !turn)) { 
				Count += 1; 
				return true; 
			} 
		} 
		return false; 
	} 

	// Function to find nodes common to given two nodes 
	static int NumberOfTurn(Node root, int first, int second) { 
		Node LCA = findLCA(root, first, second); 

		// there is no path between these two node 
		if (LCA == null) 
			return -1; 
		Count = 0; 

		// case 1: 
		if (LCA.key != first && LCA.key != second) { 

			// count number of turns needs to reached 
			// the second node from LCA 
			if (CountTurn(LCA.right, second, false) 
					|| CountTurn(LCA.left, second, true)) 
				; 

			// count number of turns needs to reached 
			// the first node from LCA 
			if (CountTurn(LCA.left, first, true) 
					|| CountTurn(LCA.right, first, false)) 
				; 
			return Count + 1; 
		} 

		// case 2: 
		if (LCA.key == first) { 

			// count number of turns needs to reached 
			// the second node from LCA 
			CountTurn(LCA.right, second, false); 
			CountTurn(LCA.left, second, true); 
			return Count; 
		} else { 

			// count number of turns needs to reached 
			// the first node from LCA1 
			CountTurn(LCA.right, first, false); 
			CountTurn(LCA.left, first, true); 
			return Count; 
		} 
	} 

	// Driver program to test above functions 
	public static void main(String[] args) { 
		
		Node root = new Node(1); 
		root.left = new Node(2); 
		root.right = new Node(3); 
		root.left.left = new Node(4); 
		root.left.right = new Node(5); 
		root.right.left = new Node(6); 
		root.right.right = new Node(7); 
		root.left.left.left = new Node(8); 
		root.right.left.left = new Node(9); 
		root.right.left.right = new Node(10); 

		int turn = 0; 
		if ((turn = NumberOfTurn(root, 5, 10)) != 0) 
			System.out.println(turn); 
		else
			System.out.println("Not Possible"); 
	} 

} 

