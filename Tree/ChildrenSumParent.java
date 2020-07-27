class ChildrenSumParent
{
    public static int isSumProperty(Node node)
    {
        if(node == null || node.left == null && node.right == null){
            return 1;
        }
        
        int ls = 0;
        int rs = 0;
        if(node.left !=null){
            ls = node.left.data;
        }
        
        if(node.right != null){
            rs = node.right.data;
        }
        
        if(ls + rs == node.data && isSumProperty(node.left) != 0 && isSumProperty(node.right) != 0 ){
            return 1;
        }
        else{
            return 0;
        }
    }
}