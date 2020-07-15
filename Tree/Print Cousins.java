/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
public class Solution {
    ArrayList<Integer> ans;
    public ArrayList<Integer> solve(TreeNode root, int node) {
        ans = new ArrayList<>();
        
        int level = getLevel(root, node, 1);
        printGivenLevel(root, node, level);
        
        return ans;
        
    }
    
    void printGivenLevel(TreeNode root, int node, int level)  
    {  
        // Base cases  
        if (root == null || level < 2)  
            return;  
      
        // If current node is parent of a node with  
        // given level  
        if (level == 2)  
        {  
            if ((root.left != null && root.left.val == node) || (root.right != null && root.right.val == node))  
                return;  
            if (root.left != null)  
                ans.add(root.left.val);
            //System.out.print(root.left.data + " ");  
            if (root.right != null)  
                ans.add(root.right.val);
            //System.out.print(root.right.data + " ");  
        }  
      
        // Recur for left and right subtrees  
        else if (level > 2)  
        {  
            printGivenLevel(root.left, node, level-1);  
            printGivenLevel(root.right, node, level-1);  
        }  
    }
    
    
    int getLevel(TreeNode root, int node, int level)  
    {  
        // base cases  
        if (root == null)  
            return 0;  
        if (root.val == node)  
            return level;  
      
        // If node is present in left subtree  
        int downlevel = getLevel(root.left, node, level+1);  
        if (downlevel != 0)  
            return downlevel;  
      
        // If node is not present in left subtree  
        return getLevel(root.right, node, level+1);  
    }
}
