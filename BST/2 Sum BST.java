public class Solution {
    public int t2Sum(TreeNode A, int B) {
        
        HashSet<Integer>set=new HashSet<>();
        Queue<TreeNode>q=new LinkedList<>();
    
        q.add(A);
        while(!q.isEmpty()) {
            TreeNode temp=q.poll();
            if(set.contains(B-temp.val)) return 1;
            else set.add(temp.val);
            
            if(temp.left!=null) q.add(temp.left);
            if(temp.right!=null) q.add(temp.right);
        }
        
        
        return 0;
    }
}