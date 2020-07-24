public class Solution {
    public TreeNode solve(TreeNode t1, TreeNode t2) {
        
        if(t1 == null && t2 == null)
        return null;
        else if(t1 == null)
        return t2;
        else if(t2 == null)
        return t1;
        else {
        TreeNode root = new TreeNode(t1.val + t2.val);
        root.left = solve(t1.left,t2.left);
        root.right = solve(t1.right,t2.right);
        return root;
        }
        
        
    }
}

/*

Input

       2

      / \

     1   4

    /

   5


        3
      / \
      6  1
      \   \
       2   7



output


         5
        / \
       7   5
      / \   \ 
     5   2   7



*/