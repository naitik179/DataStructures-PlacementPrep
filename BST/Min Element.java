class Tree
{
    int minValue(Node node)
    {
        if(node == null){
            return -1;
        }
        
        int minval = node.data;
        while(node.left !=null){
            minval = node.left.data;
            node = node.left;
        }
        
        return minval;
            
    }
}