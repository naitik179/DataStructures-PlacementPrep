/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode flatten(TreeNode a) {
        
        if(a == null){
            return a;
        }
        
        Stack<TreeNode>st = new Stack<>();
        st.push(a);
        
        while(!st.isEmpty()){
            TreeNode curr = st.pop();
            if(curr.right != null){
                st.push(curr.right);
            }
            if(curr.left != null){
                st.push(curr.left);
            }
            
            if(!st.isEmpty()){
                curr.right = st.peek();
            }
            
            curr.left = null;
        }
        
        
        return a;
    }
}
