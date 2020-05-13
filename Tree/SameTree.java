import java.util.*;

class Node{
    int data;
    Node left,right;

    Node(int x){
        data = x;
        left=null;
        right = null;
    }
}

class SameTree{
    Node root;

    public boolean isSameTree(Node p, Node q) {
        
        int flag=0;
        
        Queue<Node>q1 = new LinkedList<Node>();
        Queue<Node>q2 = new LinkedList<Node>();
        
        if((p == null && q != null) || (p!=null && q == null) ){
            return false;
        }
        else{
            q1.add(p);
            q2.add(q);
            
            while(!q1.isEmpty() && !q2.isEmpty()){
                
                Node pp = q1.poll();
                Node qq = q2.poll();
                
                
                if(pp == null && qq == null )
                    continue;
                if(pp == null || qq == null)
                    return false;
        
                if(pp.data != qq.data)
                    return false;
         
                q1.add(pp.left);
                q2.add(qq.left);
                q1.add(pp.right);
                q2.add(qq.right);
                }
        }
        
        return true;  
        
}

  

    public static void main(String args[]){

        SameTree tree = new SameTree();

        tree.root = new Node(1); 
        tree.root.left = new Node(2); 
        tree.root.right = new Node(3); 
        tree.root.left.left = new Node(4); 
        tree.root.left.right = new Node(5); 

        SameTree tree2 = new SameTree();
        tree2.root = new Node(1); 
        tree2.root.left = new Node(2); 
        tree2.root.right = new Node(3); 
        tree2.root.left.left = new Node(4); 
        tree2.root.left.right = new Node(5); 

        boolean ans = tree.isSameTree(tree.root , tree2.root);

        System.out.println("It is " + ans + " the tree is same "); 
    }
}