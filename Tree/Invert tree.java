public class Solution {
    public static void con(TreeNode A){
        if(A == null){
            return;
        }
        con(A.left);
        con(A.right);
        
        TreeNode temp = A.left;
        A.left = A.right;
        A.right = temp;
    }
    public TreeNode invertTree(TreeNode A) {
        
       con(A);
       
       return A;
        
    }
}

/*


Given a binary tree, invert the binary tree and return it.
Look at the example for more details.

Example :
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4


*/