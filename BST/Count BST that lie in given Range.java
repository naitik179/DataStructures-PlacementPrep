public static int countrange(Node root , int l , int r)
{
    if(root == null){
        return 0;
    }
    
    else if(root.data < l){
        return countrange(root.right ,l ,r);
    }
    else if(root.data > r){
        return countrange(root.left , l ,r);
    }
    else{
        return 1 + countrange(root.left , l , r) + countrange(root.right , l , r);
    }

}
public static int getCountOfNode(Node root,int l, int h)
{
    //Your code here
    
    return countrange(root , l , h);
}