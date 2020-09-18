class Solution
{   
    public static void util(Node root , int l , int r , ArrayList<Integer>ans){
        if(root == null){
            return;
        }
        
        if(l < root.data){
             util(root.left , l , r , ans);
        }
        
        if(root.data >=l && root.data <=r){
            ans.add(root.data);
        }
        
        if(root.data < r){
             util(root.right , l , r , ans);
        }
        
    }
	public static ArrayList<Integer> printNearNodes(Node root, int low, int high)
	{
      // code here.
      ArrayList<Integer>ans = new ArrayList<>();
      util(root , low , high  , ans);
      return ans;
    }
    
}