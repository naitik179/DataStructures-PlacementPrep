public class Tree
{
    boolean checkfunction(Node node , int min , int max){
        if(node == null){
            return true;
        }
        
        if(node.data < min || node.data > max){
            return false;
        }
        
        return (checkfunction(node.left , min , node.data -1) && checkfunction(node.right , node.data +1 , max));
    }
    // return true if the given tree is a BST, else return false
    boolean isBST(Node root)
        {
            // code here.
            return checkfunction(root , Integer.MIN_VALUE, Integer.MAX_VALUE);
            
        }
}