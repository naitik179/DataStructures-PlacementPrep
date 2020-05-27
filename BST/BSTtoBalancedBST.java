import java.util.Scanner;
import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
    int data;
    Node right, left;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}

class BinarySearchTree
{
     static Node insert(Node node, int data)
    {
     if (node == null)
     {
            return (new Node(data));
    } else 
        {
             
            /* 2. Otherwise, recur down the tree */
            if (data <= node.data)
            {
                node.left = insert(node.left, data);
            } else 
            {
                node.right = insert(node.right, data);
            }
 
            /* return the (unchanged) node pointer */
            return node;
        }
    
    }
    
    int height(Node node) 
{
   if (node==null) return 0;
   else
   {
       int lDepth = height(node.left);
       int rDepth = height(node.right);
       if (lDepth > rDepth)
           return(lDepth+1);
       else 
           return(rDepth+1);
   }
} 
    
         public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            Node root = null;
            
            while(n-- > 0)
            {
                int data = sc.nextInt();
                root = insert(root, data);
            }
           
             BSTtoBalancedBST gfg = new BSTtoBalancedBST();
             
           root =  gfg.buildBalancedTree(root);
            // preOrder(root);
            BinarySearchTree bst = new BinarySearchTree();
             System.out.println(bst.height(root));
        }
    }
    
     void preOrder(Node node) 
    {
        if (node == null)
            return;
        System.out.print(node.data + " ");
        preOrder(node.left);
        preOrder(node.right);
    }
}

class BSTtoBalancedBST
{
    
    public static void inorder(Node node , Vector<Node>v){
        
        if(node == null){
            return;
        }
        inorder(node.left , v);
        v.add(node);
        inorder(node.right ,v);
        
    }
    
    public static Node buildbalancedtree(int start , int end , Vector<Node>v){
        
        if(start > end){
            return null;
        }
        
        int mid = (start + end)/2;
        
        Node n = v.get(mid);
        
        n.left = buildbalancedtree(start , mid -1 , v);
        n.right = buildbalancedtree(mid +1 , end , v);
        
        return n;
    }
    Node buildBalancedTree(Node root) 
    {
        //Add your code here.
        
        Vector<Node>v = new Vector<>();
        
        inorder(root , v);
        int n = v.size();
        
        return buildbalancedtree(0 , n-1 , v);
    }
}
