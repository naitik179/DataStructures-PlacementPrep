class Tree {
    
    
    boolean areMirror(Node a, Node b) {
        // Your code here
        
        if(a == null && b == null){
            return true;
        }
        if(a == null || b== null){
            return false;
        }
        if(a.data != b.data){
            return false;
        }
        else{
            return (areMirror(a.left , b.right) && areMirror(a.right , b.left));
        }
    }
}