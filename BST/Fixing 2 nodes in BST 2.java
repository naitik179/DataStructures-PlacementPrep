class Sol
{
    static Node prev , first , second;
    
    public static void INORDER(Node root) {
        if (root == null)
            return;
        INORDER(root.left);
        if (prev != null && prev.data > root.data) {
            if (first == null) 
            {
                first = prev;
            }
            second = root;
        }
        prev = root;
        INORDER(root.right);
    }
    public Node correctBST(Node root)
    {
        //code here.
        
        prev = null;
        first = null;
        second = null;
        INORDER(root);
        int temp = first.data;
        first.data = second.data;
        second.data = temp;
        
           
        return root;
    }
 
}