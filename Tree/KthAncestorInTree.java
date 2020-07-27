class Tree
{
    
    public boolean findpath(Node root , int n , List<Integer>path){
        if(root == null){
            return false;
        }
        
        path.add(root.data);

        if (root.data == n) {
            return true;
        }

        if (root.left != null && findpath(root.left, n , path)) {
            return true;
        }

        if (root.right != null && findpath(root.right, n , path)) {
            return true;
        }

        // If not present in subtree rooted with root,
        // remove root from path[] and return false
        path.remove(path.size() - 1);

        return false;
    
    }
    public int kthAncestor(Node root, int k, int node)
    {
       List<Integer>path = new ArrayList<>();
       int ans = -1;
       
       if(!findpath(root , node , path) || path.size() - k < 0){
           ans = -1;
       }
       
       if(path.size() - k  > 0)
       {
           
           for(int i=0;i<path.size()-k;i++){
               ans = path.get(i);
           }
       }
       
       return ans;
    }
}