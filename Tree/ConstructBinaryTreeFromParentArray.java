class ConstructBinaryTreeFromParentArray
{
   
    public static Node createTree(int arr[], int n)
    {
        HashMap<Integer , Node>hm = new HashMap<>();
        Node root = null;
        Node temp ;
        int i;
        
        for(i=0;i<n;i++){
            
            if(hm.get(i) == null){
                
                temp = new Node(i);
                hm.put(i , temp);
            }
            
            if(arr[i] == -1){
                root = hm.get(i);
            }
            
            // not root and parent of the node is not created
            else if(hm.get(arr[i]) == null){
                temp = new Node(arr[i]);
                
                temp.left = hm.get(i);
                
                hm.put(arr[i] , temp);
            }
            
            
            else {
                
                if(hm.get(arr[i]).left == null)
                {
                    hm.get(arr[i]).left = hm.get(i);
                }
                else{
                    hm.get(arr[i]).right = hm.get(i);
                }
            }
            
        }
        
        return root;
    }
    
}