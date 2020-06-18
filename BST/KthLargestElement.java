class Tree
{
    
    // return the Kth largest element in the given BST rooted at 'root'
    public int kthLargest(Node root,int K)
    {
        Node current = root;
        Node KthLargest = null;
        int count = 0;
            while(current != null)
            {
                if(current.right == null)
                {
                    count=count+1;
   	                if(count == K)
                    KthLargest = current;
                current = current.left;
                }
                else
                {
                    // get the inorder successor of current and connect with current 
                    Node successor = current.right;
                    while (successor.left != null && successor.left != current)
                        successor = successor.left;
                        if (successor.left == null)
                        {
                            successor.left = current;
                            current = current.right;
                        }
                        else
                        {
                            successor.left = null;
                            count=count+1;
                                if(count == K)
                                KthLargest = current;
                            current = current.left;
                        }
                }
            }
        return KthLargest.data;
    }
}