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

class DepthofTree{
    Node root;

    int maxdepth(Node node){


        int depth =0;
        if(node == null){
            return 0;
        }
        else{

            int l = maxdepth(node.left);
            int r = maxdepth(node.right);

            //depth of the root is added

            depth = Math.max(l ,r) + 1;
            return depth;

        }
    }

    public static void main(String args[]){

        DepthofTree tree = new DepthofTree();

        tree.root = new Node(1); 
        tree.root.left = new Node(2); 
        tree.root.right = new Node(3); 
        tree.root.left.left = new Node(4); 
        tree.root.left.right = new Node(5); 
   
        System.out.println("Height of tree is : " +  tree.maxdepth(tree.root)); 
    }
}