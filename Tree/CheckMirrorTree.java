class Node 
{ 
	int data; 
	Node left, right; 

	public Node(int data) 
	{ 
		this.data = data; 
		left = right = null; 
	} 
} 

class CheckMirrorTree 
{ 
	Node a, b; 
	

	boolean areMirror(Node a, Node b) 
	{ 
		
        if(a == null && b == null){
            return true;
        }
        
        if(a == null || b == null){
            return false;
        }
        if(a.data != b.data){
            return false;
        }
        else{
            if(a.left != null && b.right != null)
            {
                return areMirror(a.left , b.right);
            }
            else if(a.right != null && a.left != null){
                return areMirror(a.right , b.left);
            }
        }
        
        return true; 
	} 

	// Driver code to test above methods 
	public static void main(String[] args) 
	{ 
		CheckMirrorTree tree = new CheckMirrorTree(); 
		Node a = new Node(1); 
		Node b = new Node(1); 
		a.left = new Node(2); 
		a.right = new Node(3); 
		a.left.left = new Node(4); 
		a.left.right = new Node(5); 

		b.left = new Node(3); 
		b.right = new Node(2); 
		b.right.left = new Node(5); 
		b.right.right = new Node(4); 

		if (tree.areMirror(a, b) == true) 
			System.out.println("Yes"); 
		else
			System.out.println("No"); 

	} 
} 

