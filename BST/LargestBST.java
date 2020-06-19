class Solution{
    
    public static int size(Node root){
        if(root == null){
            return 0;
        }
        
        return (size(root.left) + 1 + size(root.right));
    }
    
    public static boolean isBST(Node node , int min , int max){
        if(node == null){
            return true;
        }
        
        if(node.data < min || node.data > max){
            return false;
        }
        
        return (isBST(node.left , min , node.data-1) && isBST(node.right , node.data+1 , max ));
    }
    
    // Return the size of the largest sub-tree which is also a BST
    static int largestBst(Node root)
    {
        if(isBST(root , Integer.MIN_VALUE , Integer.MAX_VALUE)){
            return size(root);
        }
        
        return Math.max(largestBst(root.left) , largestBst(root.right));
        
        
    }
    
}