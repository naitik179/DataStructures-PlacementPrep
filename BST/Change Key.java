class GfG 
{ 

static class node 
{ 
	int key; 
	node left, right; 
} 
static node root = null; 

// A utility function to 
// create a new BST node 
static node newNode(int item) 
{ 
	node temp = new node(); 
	temp.key = item; 
	temp.left = null; 
	temp.right = null; 
	return temp; 
} 

// A utility function to 
// do inorder traversal of BST 
static void inorder(node root) 
{ 
	if (root != null) 
	{ 
		inorder(root.left); 
		System.out.print(root.key + " "); 
		inorder(root.right); 
	} 
} 

/* A utility function to insert 
a new node with given key in BST */
static node insert(node node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == null) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node.key) 
		node.left = insert(node.left, key); 
	else
		node.right = insert(node.right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

/* Given a non-empty binary search tree, 
return the node with minimum key value 
found in that tree. Note that the entire 
tree does not need to be searched. */
static node minValueNode(node Node) 
{ 
	node current = Node; 

	/* loop down to find the leftmost leaf */
	while (current.left != null) 
		current = current.left; 

	return current; 
} 

/* Given a binary search tree and 
a key, this function deletes the key 
and returns the new root */
static node deleteNode(node root, int key) 
{ 
	// base case 
	if (root == null) return root; 

	// If the key to be deleted is 
	// smaller than the root's key, 
	// then it lies in left subtree 
	if (key < root.key) 
		root.left = deleteNode(root.left, key); 

	// If the key to be deleted is 
	// greater than the root's key, 
	// then it lies in right subtree 
	else if (key > root.key) 
		root.right = deleteNode(root.right, key); 

	// if key is same as root's 
	// key, then This is the node 
	// to be deleted 
	else
	{ 
		// node with only one child or no child 
		if (root.left == null) 
		{ 
			node temp = root.right; 
			return temp; 
		} 
		else if (root.right == null) 
		{ 
			node temp = root.left; 
			return temp; 
		} 

		// node with two children: Get 
		// the inorder successor (smallest 
		// in the right subtree) 
		node temp = minValueNode(root.right); 

		// Copy the inorder successor's 
		// content to this node 
		root.key = temp.key; 

		// Delete the inorder successor 
		root.right = deleteNode(root.right, temp.key); 
	} 
	return root; 
} 

// Function to decrease a key 
// value in Binary Search Tree 
static node changeKey(node root, int oldVal, int newVal) 
{ 
	// First delete old key value 
	root = deleteNode(root, oldVal); 

	// Then insert new key value 
	root = insert(root, newVal); 

	// Return new root 
	return root; 
} 

// Driver code 
public static void main(String[] args) 
{ 
	/* Let us create following BST 
			50 
		/ \ 
		30 70 
		/ \ / \ 
	20 40 60 80 */
	root = insert(root, 50); 
	root = insert(root, 30); 
	root = insert(root, 20); 
	root = insert(root, 40); 
	root = insert(root, 70); 
	root = insert(root, 60); 
	root = insert(root, 80); 


	System.out.println("Inorder traversal of the given tree"); 
	inorder(root); 

	root = changeKey(root, 40, 10); 

	/* BST is modified to 
			50 
		/ \ 
		30 70 
		/ / \ 
	20 60 80 
	/ 
	10 */
	System.out.println("\nInorder traversal of the modified tree "); 
	inorder(root); 
} 
} 
 
