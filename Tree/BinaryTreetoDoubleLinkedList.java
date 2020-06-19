class GfG
{
    Node head;
    Node prev = null;
    Node bToDLL(Node root)
    {
	
	    if(root== null){
            return head;
        }
        
        bToDLL(root.left);
        
        
        if(head == null){
            head = root;
            prev = root;
        }
        else{
            root.left = prev;
            prev.right = root;
            prev = root;
        }
        
        bToDLL(root.right);
        
        return head;

    }
}