class GfG
{
    static int maxi ;
    public static void find(Node node ,  int val){
        
        if(node == null){
            return;
        }
        
        if(node.data > val){
            find(node.left  ,val);
        }
        
        if(node.data <= val){
            maxi = Math.max(maxi , node.data);
            find(node.right , val);
        }
       
        
        return;
        
    }
    public static int findMaxforKey(Node node, int val, int size)
    {
    //Add your code here.
    maxi = -1;
    find(node , val);
    return maxi;
        
    }
}


